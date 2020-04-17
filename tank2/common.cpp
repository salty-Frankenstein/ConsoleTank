#include"common.h"

HANDLE GetStdOHdl() {
	static HANDLE stdoutHdl = GetStdHandle(STD_OUTPUT_HANDLE);
	return stdoutHdl;
}
