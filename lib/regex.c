/* Pattern:
 *	x               match charater 'x'
 *  .               any charater
 *  [xyz]           either 'x', 'y' or 'z'
 *  [a-z]           j through o
 *  [^abc]          any charater but these in the set <'a', 'b', 'c'>
 *  [a-z]{-}[aeiou] the lowercase consonants
 *  r*              zero or more r's
 *  r+              one or more r's
 *  r?              zero or one
 *  r{m,n}          anywhere from m to n r's
 *  r{m,}           at least m
 *  r{,n}           at most n
 *  r{n}            exactly n
 *  \0              NUL
 *  \x12            character with hex value 0x12
 *  \123            charater with octal value 123
 *  (r)             paraentheses are used to overide precedence
 *  (?r-s:pattern)  apply option r and omit option s
 *                  'i' means case-insensitive, '-i' means case-sensitive
 *                  's' alters the meaning of '.' syntax to match any
 *                      single byte
 *                  '-s' any byte except '\n'
 *                  'x' ignore comments and whitespace in patterns
 *                      eg. (?x:a  / * * / b) equivalent to 'ab'
 *  (?#comment)
 *  rs, r|s
 *  r/s             an 'r' but only if it is followed by an 's'
 *  ^r              an 'r' at the begining of a line
 *  r$              an 'r' at the end of a line
 *
 * Model:
 *  edge in DFA:
 *    <.>, <range>,
 *
 *  equivalency:
 *    r+ --> rr*
 *    r? --> (|r)r
 *    r{m,n}  -->  rrrrrrrrrrrrrr?r?r?r?r?r?r?
 *                 \------------/            /
 *                  \     m                 /
 *                   \---------------------/
 *                               n
 *    (?option:)  shouldn't nest
 */

/*
typedef struct edge_t {
	int bt;
	union {
		int ch;
		struct {
			int from, to;
		};
	};
} edge_t;

typedef struct nfa_t {
	int a;
} nfa_t;

typedef struct regex_t {
	char *pat;
} regex_t;

void add_edge(nfa_t *nfa, int cur_state, int new_state) {
}

char escape_charater(const char *pat, int *len) {
}

regex_t *regcomp(const char *pat) {
	int i = 0, cur_state = 0, new_state = 0;;
	nfa_t nfa;
	edge_t edge;
	while(pat[i]) {
		//special character:[ ] ( ) \ . * + ? { }
		switch(pat[i]) {
		case '[':
			for(i++;pat[i] != ']';i++) {
				if(pat[i + 1] != '-') {
					add_edge(&nfa, cur_state, new_state, &edge);
				}else{
					int len = 0;
					int ch = escape_charater(&pat[i + 2], &len);
					edge.from = pat[i];
					edge.to = ch;
					i = i + len + 1;
				}
			}
			break;
		case '{':
			match_range();
			break;
		case '\\':
			match_escape_char();
			break;
		case '.':
			add_edge(ANY);
			break;
		case '*':
			repeat_last_regex(STAR);
			break;
		case '+':
			repeat_last_regex(PLUS);
			break;
		case '?':
			repeat_last_regex(ONE);
			break;
		}
	}
}
*/
