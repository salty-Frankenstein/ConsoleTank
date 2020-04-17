#include"tankbase.h"
using namespace std;

TankBase::TankBase(int _length, int _width, int _x, int _y)
	: Sprite(LAYER_TANK) {
	length = _length;
	width = _width;
	direction = D_UP;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
}

inline void TankBase::Show() {
	//do the cleaning
	auto pos = posLast;
	
	if (direction == D_UP || direction == D_DOWN) {
		for (int i = 1; i <= width; i++) {
			SetConsoleCursorPosition(GetStdOHdl(), pos);
			pos.Y++;
			for (int j = 1; j <= length; j++)
				wcout << L'　';
			//putchar('\n');
		}
	}
	else {
		for (int i = 1; i <= length; i++) {
			SetConsoleCursorPosition(GetStdOHdl(), pos);
			pos.Y++;
			for (int j = 1; j <= width; j++)
				wcout << L'　';
			//putchar('\n');
		}
	}
	
	//draw a new frame
	DrawTank();
}
