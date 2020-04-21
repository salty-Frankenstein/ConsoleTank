#pragma once
#include"tankbase.h"

/* 轻型坦克 */
class EnemyTank :public TankBase {
public:
	EnemyTank(int x, int y, int hp, int damage, int speed);
	void Update();
	void DrawTank();
protected:
	void GoStraight();
	const static int WIDTH_X = 3;
	const static int WIDTH_Y = 3;
	static const wchar_t image[WIDTH_X][WIDTH_Y];
	//const static int HP = 1;
	//const static int DAMAGE = 1;
	//const static int SPEED = 1;
};
