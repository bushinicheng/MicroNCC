#include "common.h"

extern bool is_syntax_error;
void *get_memory_pointer();
void require_memory(size_t size);

static const char *ErrorReason[] = {
	[ErrorInvalidNUM] = "error type A: invalid number.",
	[ErrorInvalidOCT] = "error type A: invalid oct number.",
	[ErrorInvalidHEX] = "error type A: invalid hex number.",
	[ErrorUnknownToken] = "error type A: invalid character.",
	[ErrorNullDecl] = "warning: declaration does not declare anything.",
	[ErrorExpectedComma] = "expected ',' here.",
	[ErrorExpectedSemi] = "expected ';' here.",
	[ErrorExpectedStmt] = "error type B: expected definition or statement here.",
	[ErrorMissingSemi] = "error type B: missing ';'",
	[ErrorMissingRC] = "error type B: missing '}'",
	[ErrorMissingRB] = "error type B: missing ']'",
	[ErrorRedefinition] = "line %d: error: redefinition of variable '%s'",
	[ErrorNotCallable] = "line %d: error: called object '%s' is not a function",
	[ErrorCall0vx] = "line %d: note: candidate function not viable: require 0 arguments, but ? was provided",
	[ErrorCallnv0] = "line %d: note: candidate function not viable: require %d arguments, but no arguments was provided",
	[ErrorCallngtm] = "line %d: note: candidate function not viable: require %d arguments, but %d arguments was provided",
	[ErrorCallnltm] = "line %d: note: candidate function not viable: require %d arguments, but too much arguments was provided",
	[ErrorCallParameterNotMatch] = "line %d: note: %dth parameter of function '%s' not match.",
	[ErrorUndeclaredIdentifier] = "line %d: error: use of undeclared identifier '%s'.",
	[ErrorNotPointer] = "line %d: error: indirection requires pointer operand.",
	[ErrorTakeRvalueAddress] = "line %d: error: cannot take the address of an rvalue of type",
	[ErrorUnaryOperatorMismatch] = "line %d: error: invalid argument type to unary",
	[ErrorAssignIncompatible] = "line %d: error: assigning to '%s' from incompatible type",
	[ErrorReferenceStructMember] = "line %d: error: member reference base type '%s' is not a structure or union",
	[ErrorNoSuchMember] = "line %d: error: no member named '%s' in '%s'",
	[ErrorReferenceNotPointer] = "line %d: error: member reference type '%s' is not a pointer",
};

char *sformat(const char *format, ...) {
	char *ret_str = (char *)get_memory_pointer();
	va_list ap;
	va_start(ap, format);
	int len = vsprintf(ret_str, format, ap);
	require_memory(len + 1);
	return ret_str;
}

int yydebug(int lineno, int column, int tokenlen, enum ErrorType errortype)
{
	extern char yylinetext[1024];
	printf("%d:%d: %s\n", lineno, column, ErrorReason[errortype]);
	printf("%s\n", yylinetext);
	for(int i = 0; i < column-1; i++)
	{
		if(yylinetext[i]=='\t')
			printf("\t");
		else
			printf(" ");
	}
	for(int i = 0; i < tokenlen; i++)
		printf("^");
	printf("\n");
	return 0;
}

int yyerr(const char *format, ...)
{
	int done;
	va_list arg;
	extern int curlineno;
	va_start(arg, format);
	done = vfprintf(stderr, format, arg);
	va_end(arg);
	return done;
}

int yyerrtype(int errortype, ...) {
	int done;
	va_list arg;
	extern int curlineno;
	is_syntax_error = true;
	va_start(arg, errortype);
	done = vfprintf(stderr, ErrorReason[errortype], arg);
	fprintf(stderr, "\n");
	va_end(arg);
	return done;
}


/*for compatibility*/
int yyerror(const char *format, ...)
{
	int done;
	va_list arg;
	extern int curlineno;
	va_start(arg, format);
	logd("%d: error type B: ", curlineno);
	done = vfprintf(stderr, format, arg);
	logd("\n");
	va_end (arg);
	return done;
}

int yylog(FILE *fp, const char *tag, const char *format, ...)
{
	va_list arg;
	int done;
	
	va_start(arg, format);
	fprintf(fp, "%s", tag);
	done = vfprintf(fp, format, arg);
	fprintf(fp, "\033[0m");
	va_end (arg);
	
	return done;
}

int __attribute__((noinline)) set_break(){return 0;}
