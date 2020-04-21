#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
using namespace std;

GameTime Game::gameTime = 0;

Game::Game() {
	//system("chcp 65001");
	//system("cls");
	system("mode con cols=160 lines=85");
	wcout.imbue(locale(""));
	CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 9; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE));
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);

	stdoutHdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(stdoutHdl, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(stdoutHdl, &CursorInfo);

	Sprite::bufferHdl = &buf;
}

void Game::Run() {
	//Buffer buf;
	buf.Push(make_shared<PlayerTank>());
	buf.Push(make_shared<EnemyTank>(6, 6, 1, 1, 1));
	//buf.Push(make_shared<Bullet>(S_PLAYER_BULLET, 36, 36, D_LEFT));
	shared_ptr<Background> bg = make_shared<Background>();
	bg->Draw();
	buf.Push(bg);
	
	while (1) {
		//cout << buf.Size() << endl;
		buf.Show();
		buf.Update();
		Sleep(30);
		gameTime++;
	}
}

GameTime Game::GetGameTime() {
	return gameTime;
}
