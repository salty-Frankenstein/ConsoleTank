#pragma once
#include"common.h"
#include"sprite.h"
#include<iostream>
#include<fstream>
#include<string>

class Background :public Sprite {
public:
	void Show();
	void Update();
	void Draw();	//drawing for borders
private:

};
