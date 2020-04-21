#pragma once
#include"sprite.h"
#include"common.h"
#include<iostream>

const int BARRIER_LAYER = 5;

class Barrier :public Sprite {
public:
	Barrier(int x, int y, SpriteType type);
	virtual void Show() = 0;
	void Update();
};

class IronWall :public Barrier {
public:
	IronWall(int x, int y);
	void Show();
};
