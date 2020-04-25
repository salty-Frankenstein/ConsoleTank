#pragma once
#include"common.h"
#include"sprite.h"
#include<string>
#include<vector>


class Button :public Sprite {
public:
	Button(int x, int y, std::string name);
	void Show();
	void Update();
	void Delete();
	void Press();
	bool isActive;
private:
	std::string name;
};

