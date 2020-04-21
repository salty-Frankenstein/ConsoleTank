#include"tankbase.h"
using namespace std;

TankBase::TankBase(SpriteType type, int _widthX, int _widthY,
	int _x, int _y, int _hp, int _damage, int _speed)
	: Sprite(LAYER_TANK, type) {
	widthX = _widthX;
	widthY = _widthY;
	dirCur = D_UP;
	dirLast = D_LEFT;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
	hp = _hp;
	damage = _damage;
	speed = _speed;
}

inline void TankBase::Show() {
	//do the cleaning
	if (posLast.Y == posCur.Y && posLast.X == posCur.X
		&& dirLast == dirCur)return;
	auto pos = posLast;
	
	if (dirCur == D_UP || dirCur == D_DOWN) {
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

inline int TankBase::GetWidthX()const {
	return widthX;
}

inline int TankBase::GetWidthY()const {
	return widthY;
}

void TankBase::GetDamage(int damage) {
	hp -= damage;
}
