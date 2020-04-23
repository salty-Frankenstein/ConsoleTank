#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
using namespace std;

GameTime Game::gameTime = 0;

Game::Game() :score(GRID_X * 2 + 10, 10, 5) {
	//system("chcp 65001");
	//system("cls");
	system("mode con cols=160 lines=85");
	wcout.imbue(locale(""));
	CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 8; // leave X as zero
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
	buf.Push(shared_ptr<Number>(&score));
}

void Game::Run() {
	system("cls");
	buf.Push(make_shared<PlayerTank>());
	
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<LightTank>(16 + i * 16, 2 + j * 16));
			else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));
	
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<AntiTankGun>(16 + i * 16, 2 + j * 16 - 5));
			//else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));

	shared_ptr<Background> bg = make_shared<Background>();
	bg->Draw();
	buf.Push(bg);
	for (int i = 1; i <= 45; i++)
		buf.Push(make_shared<IronWall>(2 * i + 6, 30));
	for (int i = 4; i <= 45; i++) {
		buf.Push(make_shared<BrickWall>(2 * i + 6, 40));
		buf.Push(make_shared<BrickWall>(2 * i + 6, 41));
		buf.Push(make_shared<BrickWall>(2 * i + 6, 42));
	}
		
	for (int i = 1; i <= 45; i++)
		buf.Push(make_shared<IronWall>(2 * i + 6, 50));
	while (1) {
		//cout << buf.Size() << endl;
		score.SetNumber(gameTime);
		buf.Sort();
		buf.Show();
		buf.Update();
		Sleep(30);
		gameTime++;
	}
}

GameTime Game::GetGameTime() {
	return gameTime;
}
