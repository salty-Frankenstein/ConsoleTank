#pragma once
#include"common.h"
#include"gameobject.h"

class Menu {
public:
	Menu();
	void Run();
private:
	enum MenuButton { M_GAMESTART, M_EXIT };
	Buffer buf;
	static const int BUTTON_NUM = 2;
	std::shared_ptr<Button> buttons[BUTTON_NUM];
	int nowActive;
};
