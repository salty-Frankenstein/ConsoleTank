#include"tankbase.h"
using namespace std;

TankBase::TankBase(int _widthX, int _widthY, int _x, int _y)
	: Sprite(LAYER_TANK) {
	widthX = _widthX;
	widthY = _widthY;
	direction = D_UP;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
}

inline void TankBase::Show() {
	//do the cleaning
	auto pos = posLast;
	
	if (direction == D_UP || direction == D_DOWN) {
		for (int i = 1; i <= widthY; i++) {
			SetConsoleCursorPosition(GetStdOHdl(), pos);
			pos.Y++;
			for (int j = 1; j <= widthX; j++)
				wcout << L'　';
			//putchar('\n');
		}
	}
	else {
		for (int i = 1; i <= widthX; i++) {
			SetConsoleCursorPosition(GetStdOHdl(), pos);
			pos.Y++;
			for (int j = 1; j <= widthY; j++)
				wcout << L'　';
			//putchar('\n');
		}
	}
	
	//draw a new frame
	DrawTank();
}
