#pragma once
#include"sprite.h"
#include"common.h"

const int LAYER_BULLET = 3;

class Bullet :public Sprite {
public:
	Bullet(SpriteType type, int x, int y, Direction dir);
	void Update();
	void Show();
	void Delete();
private:
	COORD posLast;
	Direction dir;
	const static int SPEED = 1;
	const static wchar_t image = L'◆';
};
