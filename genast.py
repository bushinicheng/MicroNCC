#!/usr/bin/python
#coding:utf-8

import re

def get_nonterminal(stream):
    pa=re.compile(r'%(type)<.*?>(.*?)\n\n', re.S)
    result=pa.findall(stream)
    token=[re.sub('/\*.*?\*/', '', i[1]) for i in result]
    token=re.findall('\w+', ' '.join(token))
    return 'enum {{\n\tNone,\n{}\n}};'.format(',\n'.join(['\t{0}'.format(i) for i in token]))

def get_symbol(stream):
    pa=re.compile(r'%(token)<.*?>(.*?)\n\n', re.S)
    result=pa.findall(stream)
    token=[re.sub('/\*.*?\*/', '', i[1]) for i in result]
    token=re.findall('\w+', ' '.join(token))
    return 'static char* str_lexval[] = {{\n{}\n}};'.format(',\n'.join(['\t[{0}] = "{0}"'.format(i) for i in token]))

def dep(stream):
    rets = ''
    count = 0
    for ch in stream:
        if ch == '{':count = count+1;
        if count == 0:
            rets += ch
        if ch == '}':
            count = count-1
            if count == 0:
                rets += '{}'
    return rets

def get_rules(stream):
    collection=[(0, "AST_None", "None")]
    stream = re.sub('(\s+(%[^\n]*?)?{.*?}\s+)|(^\s+)', '', dep(stream), flags=re.S|re.M)
    pa=re.compile(r'^(\w+):(.*?);', re.S|re.M)
    result=pa.findall(stream)
    for items in result:
        sym=items[0]
        collection.extend([(i.count(' ')+1 if i else 0, 'AST_{}_is_{}'.format(sym, i.replace(' ', '_') if i else 'None'), sym) for i in items[1].split('|')])
    return 'enum {{\n{}\n}};'.format(',\n'.join(['\t{}'.format(j) for i,j,k in collection])), \
    'static ParNodeStruct node_struct[] = {{\n{}\n}};'.format(',\n'.join(['\t[{1}] = {{{0}, {2}, "{1}", "{2}"}}'.format(i, j, k) for i,j,k in collection]))

def get_func():
    with open('ast.c') as fp:
        stream = fp.read()
    result=re.findall('^(\w[\d\w]*\*?\s+\w[\d\w]*\(.*?\))$', stream, flags=re.M)
    return ';\n'.join(result)+';'

def genast():
    with open('syntax.y') as fp:
        stream=fp.read()
        sym=get_symbol(stream)
        nonterm = get_nonterminal(stream)
        astenum, aststruct=get_rules(stream)
        asth=\
        "#ifndef __AST_H__\n"+\
        "#define __AST_H__\n\n"+\
            nonterm+\
            "\n\n"+\
            astenum+\
        """
#ifdef __AST_C__
        
typedef struct tagParNodeStruct {
    int nr_child;
    int parent;
    const char *str_struct;
    const char *str_root;
} ParNodeStruct;

"""+\
            aststruct+\
        '\n\n#include "syntax.h"\n\n'+\
            sym+\
        "\n\n#endif\n\n"+\
            get_func()+\
        "\n\n#endif"
        print(asth)

if __name__ == "__main__":
    genast()
