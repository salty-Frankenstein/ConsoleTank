#include"button.h"
#include<iostream>
using namespace std;

Button::Button(int x, int y, string _name)
	:Sprite(x, y) {
	isActive = true;
	name = _name;
}

void Button::Show() {
	SetConsoleCursorPosition(GetStdOHdl(), posCur);
	if (isActive)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 71);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Button::Update() {}

void Button::Delete() {
	del = true;
	//SetConsoleCursorPosition(GetStdOHdl(), posCur);
	//wcout << L'¡¡';
}

void Button::Press() {
	if (isActive) {
		Delete();
	}
}

