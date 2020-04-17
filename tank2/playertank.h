#pragma once
#include "tankbase.h"


const int LENGTH = 3;
const int WIDTH = 3;

class PlayerTank :public TankBase {
public:
	PlayerTank();
	void Update();
	void DrawTank();
private:
	static const wchar_t image[LENGTH][WIDTH];
};
