#ifndef __ERROR_H__
#define __ERROR_H__

enum ErrorType {
	ErrorInvalidNUM,
	ErrorInvalidOCT,
	ErrorInvalidHEX,
	ErrorInvalidDEC,
	ErrorUnknownToken,
	ErrorNullDecl,
	ErrorExpectedComma,
	ErrorExpectedSemi,
	ErrorExpectedStmt,
	ErrorMissingSemi,
	ErrorMissingRC,
	ErrorMissingRB,
	ErrorRedefinition,
	ErrorNotCallable,
	ErrorCall0vx,
	ErrorCallnv0,
	ErrorCallngtm,
	ErrorCallnltm,
	ErrorCallParameterNotMatch,
	ErrorUndeclaredIdentifier,
	ErrorNotPointer,
	ErrorTakeRvalueAddress,
	ErrorUnaryOperatorMismatch,
	ErrorAssignIncompatible,
	ErrorReferenceStructMember,
	ErrorNoSuchMember,
	ErrorReferenceNotPointer,
	ErrorInvalidOperand,
	ErrorIndexNotInteger,
	ErrorSubscripted,
	ErrorNotAssignable,
};

int yydbg(int, int, int, enum ErrorType);
int yyerr(const char *, ...);
int yyerror(const char *, ...);//called only by YACC
int yylog(FILE *fp, const char *tag, const char *, ...);
int yyerrtype(int errortype, ...);

bool check_dupset(char *dupreason, void *set, size_t len, size_t nitsize, off_t off);

#endif
