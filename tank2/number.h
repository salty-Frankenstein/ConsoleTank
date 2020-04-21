#pragma once
#include"common.h"
#include"sprite.h"
#include<string>
#include<iostream>

class Number :public Sprite {
public:
	Number(int x, int y, int length);
	void Show();
	void Update();
	void SetNumber(int x);
private:
	int numberNow;
	int numberSet;
	const int LENGTH;
	const static wchar_t image[10][6][4];
};
