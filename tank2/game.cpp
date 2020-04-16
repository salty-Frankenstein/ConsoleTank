#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
using namespace std;

Game::Game() {
	//system("chcp 65001");
	//system("cls");
	system("mode con cols=120 lines=46");
	wcout.imbue(locale(""));
	CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 10; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

	stdoutHdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(stdoutHdl, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(stdoutHdl, &CursorInfo);
}

void Game::Run() {
	Buffer buf;
	buf.Push(make_shared<PlayerTank>());
	while (1) {
		buf.Show();
		buf.Update();
		Sleep(30);
	}
}
