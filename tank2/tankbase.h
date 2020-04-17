﻿#pragma once
#include"common.h"
#include"sprite.h"
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <iostream>

enum Direction { D_UP, D_DOWN, D_LEFT, D_RIGHT };
const int LAYER_TANK = 3;
/* base class for tank objects */
class TankBase :public Sprite {
public:
	TankBase(int _length, int _width, int _x, int _y);
	virtual void Update() = 0;		//override: the update method
	void Show();
	virtual void DrawTank() = 0;	//override: draw the tank appearance
protected:
	Direction direction;
	COORD posLast;		//the tank object's position last frame
	COORD posCur;		//the tank object's position now
private:
	int length;
	int width;
};

