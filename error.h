#ifndef __ERROR_H__
#define __ERROR_H__

enum ErrorType {
	ERR_INVALID_NUM,
	ERR_INVALID_OCT,
	ERR_INVALID_HEX,
	ERR_INVALID_DEC,
	ERR_UNKNOWN_TOKEN
};

const char *ErrorReason[] = {
	[ERR_INVALID_NUM] = "invalid number.",
	[ERR_INVALID_OCT] = "invalid oct number.",
	[ERR_INVALID_HEX] = "invalid hex number.",
	[ERR_INVALID_DEC] = "invalid dec number."
	[ERR_UNKNOWN_TOKEN] = "unknown token."
};

#endif
