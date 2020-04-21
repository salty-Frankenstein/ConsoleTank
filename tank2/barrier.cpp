﻿#include"barrier.h"
#include"game.h"
using namespace std;
Barrier::Barrier(int x, int y, SpriteType type)
	: Sprite(x, y, BARRIER_LAYER, type) {}

void Barrier::Update() {}

IronWall::IronWall(int x, int y)
	: Barrier(x, y, S_UNDESTORYABLE) {}

void IronWall::Show() {
	if (Game::GetGameTime() % REDRAW != 0)return;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
	SetConsoleCursorPosition(GetStdOHdl(), posCur);
	wcout << L'█';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
