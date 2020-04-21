#pragma once
#include"common.h"
#include"sprite.h"
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <iostream>


const int LAYER_TANK = 3;
/* base class for tank objects */
class TankBase :public Sprite {
public:
	TankBase(SpriteType type, int widthX, int widthY, 
		int x, int y, int hp, int damage, int speed);
	virtual void Update() = 0;		//override: the update method
	void Show();
	virtual void DrawTank() = 0;	//override: draw the tank appearance
	int GetWidthX()const;
	int GetWidthY()const;
	void GetDamage(int damage);
protected:
	void Clean();	//clean the drawing
	Direction dirLast;
	Direction dirCur;
	COORD posLast;		//the tank object's position last frame
	int hp;
	int damage;
	int speed;
private:
	int widthX;
	int widthY;
};

