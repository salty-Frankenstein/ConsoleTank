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
	void Delete();
};

class IronWall :public Barrier {
public:
	IronWall(int x, int y);
	void Show();
};

class BrickWall :public Barrier {
public:
	BrickWall(int x, int y);
	void Show();
};

class PlayerBase :public Barrier {
public:
	PlayerBase(int x, int y);
	void Show();
	void Delete()override;
};
