#pragma once
#include "tankbase.h"


const int PLAYERTANK_X = 3;
const int PLAYERTANK_Y = 3;

class PlayerTank :public TankBase {
public:
	PlayerTank();
	void Update();
	void DrawTank();
private:
	static const wchar_t image[PLAYERTANK_X][PLAYERTANK_Y];
};
