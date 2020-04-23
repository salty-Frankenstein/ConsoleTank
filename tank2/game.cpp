#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
using namespace std;

GameTime Game::gameTime = 0;
int Game::player = 5;

Game::Game() {
	//system("chcp 65001");
	//system("cls");
	system("mode con cols=160 lines=85");
	wcout.imbue(locale(""));
	CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 12; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE));
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);

	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(GetStdOHdl(), &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdOHdl(), &CursorInfo);
}

void Game::Run() {
	system("cls");
	int stage = 1;
	GameState state = G_MENU;
	
	while (1) {
		switch (state) {
		case G_MENU:
			DrawTitle({ 1,3 });
			break;
		case G_GAME:
			stagePtr = make_shared<Stage>(stage);
			stagePtr->Run();
			break;
		case G_HISCORE:
			break;
		case G_EXIT:
			return;
		}
	}
}

GameTime Game::GetGameTime() {
	return gameTime;
}

void Game::AddGameTime() {
	gameTime++;
}
