#include"background.h"
using namespace std;

void Background::Show() {
	//update showing score
}

void Background::Update() {

}

void Background::Draw() {
	wcout << GetStringN<GRID_X>(L'¨€') << endl;
	COORD pos{ 0, 1 };
	for (int i = 1; i <= GRID_Y - 2; i++) {
		SetConsolePosition(pos);
		wcout << L'¨€';
		pos.Y++;
	}
	pos.X = (GRID_X - 1) * 2;
	pos.Y = 1;
	for (int i = 1; i <= GRID_Y - 2; i++) {
		SetConsolePosition(pos);
		wcout << L'¨€' << endl;
		pos.Y++;
	}
	wcout << GetStringN<GRID_X>(L'¨€') << endl;
}
