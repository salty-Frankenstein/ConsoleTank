#include"tankbase.h"

TankBase::TankBase(int _length, int _width, int _x, int _y) {
	length = _length;
	width = _width;
	stdoutPtr = GetStdHandle(STD_OUTPUT_HANDLE);
	direction = D_UP;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
}

void TankBase::Show() {
	//do the cleaning
	auto pos = posLast;
	
	if (direction == D_UP || direction == D_DOWN) {
		for (int i = 1; i <= width; i++) {
			SetConsoleCursorPosition(stdoutPtr, pos);
			pos.Y++;
			for (int j = 1; j <= length; j++)
				putchar(' ');
			putchar('\n');
		}
	}
	else {
		for (int i = 1; i <= length; i++) {
			SetConsoleCursorPosition(stdoutPtr, pos);
			pos.Y++;
			for (int j = 1; j <= width; j++)
				putchar(' ');
			putchar('\n');
		}
	}
	
	//draw a new frame
	DrawTank();
}
