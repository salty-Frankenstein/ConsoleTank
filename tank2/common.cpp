#define _CRT_SECURE_NO_WARNINGS
#include"common.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

HANDLE GetStdOHdl() {
	static HANDLE stdoutHdl = GetStdHandle(STD_OUTPUT_HANDLE);
	return stdoutHdl;
}

void SetConsolePosition(COORD pos) {
	SetConsoleCursorPosition(GetStdOHdl(), pos);
}

bool IsHit(COORD pos1, int wx1, int wy1, COORD pos2, int wx2, int wy2) {
	wx1 *= 2;
	wx2 *= 2;
	double startX1 = pos1.X,
		startY1 = pos1.Y,
		endX1 = startX1 + wx1,
		endY1 = startY1 + wy1;
	double startX2 = pos2.X,
		startY2 = pos2.Y,
		endX2 = startX2 + wx2,
		endY2 = startY2 + wy2;
	return !(endY2 <= startY1 || endY1 <= startY2 || startX1 >= endX2 || startX2 >= endX1);
}

bool IsSamePos(COORD pos1, COORD pos2) {
	return pos1.X == pos2.X && pos1.Y == pos2.Y;
}

void DrawTitle(COORD pos, string file) {
	ifstream fin(file);
	while (!fin.eof()) {
		SetConsolePosition(pos);
		string s;
		getline(fin, s);
		cout << s << endl;
		pos.Y++;
	}
}

void SetFontSize(int x) {
	CONSOLE_FONT_INFOEX info = { 0 }; // ������������
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = x; // leave X as zero
	info.FontWeight = FW_NORMAL;
	wcscpy(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdOHdl(), NULL, &info);
}
