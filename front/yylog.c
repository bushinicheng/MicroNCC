#include "front-com.h"

extern bool is_syntax_error;
extern int last_syntax_error;

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

	[ErrorAssignIncompatible] = "line %d: error: assigning to '%s' from incompatible type '%s'",
	[ErrorCall0vx] = "line %d: error: candidate function not viable: require 0 arguments, but ? was provided",
	[ErrorCallngtm] = "line %d: error: candidate function not viable: require %d arguments, but %d arguments was provided",
	[ErrorCallnltm] = "line %d: error: candidate function not viable: require %d arguments, but too much arguments was provided",
	[ErrorCallnv0] = "line %d: error: candidate function not viable: require %d arguments, but no arguments was provided",
	[ErrorCallParameterNotMatch] = "line %d: error: candidate function not viable: no known conversion from '%s' to '%s' for %dth argument",
	[ErrorIndexNotInteger] = "line %d: error: array subscript is not an integer",
	[ErrorInvalidOperand] = "line %d: error: invalid operands to binary expression ('%s' and '%s')",
	[ErrorNoSuchMember] = "line %d: error: no member named '%s' in '%s'",
	[ErrorNotAssignable] = "line %d: error: expression is not assignable",
	[ErrorNotCallable] = "line %d: error: called object '%s' is not a function",
	[ErrorNotPointer] = "line %d: error: indirection requires pointer operand.",
	[ErrorRedefinition] = "line %d: error: redefinition of variable '%s'",
	[ErrorReferenceNotPointer] = "line %d: error: member reference type '%s' is not a pointer",
	[ErrorReferenceStructMember] = "line %d: error: member reference base type '%s' is not a structure or union",
	[ErrorSubscripted] = "line %d: error: subscripted value is not an array, pointer",
	[ErrorTakeRvalueAddress] = "line %d: error: cannot take the address of an rvalue of type '%s'",
	[ErrorUnaryOperatorMismatch] = "line %d: error: invalid argument type to unary",
	[ErrorUndeclaredIdentifier] = "line %d: error: use of undeclared identifier '%s'.",
};

int yydbg(int lineno, int column, int tokenlen, enum ErrorType errortype)
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
	va_start(arg, format);
	done = vfprintf(stderr, format, arg);
	va_end(arg);
	return done;
}

int yyerrtype(int errortype, ...) {
	int done;
	va_list arg;
	is_syntax_error = true;
	last_syntax_error = errortype;
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
	fprintf(stderr, "%d: error type B: ", curlineno);
	done = vfprintf(stderr, format, arg);
	fprintf(stderr, "\n");
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
