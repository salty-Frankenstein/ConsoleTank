﻿/*
	共用的常量、函数
*/
#pragma once
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string>

/* 地图长宽 */
const int GRID_X = 42;
const int GRID_Y = 42;
const int REDRAW = 20;	//优化性能用

/* 依赖路径常量 */
const char* const LOGO_PATH = "./logo/logo.txt";
const char* const GAMEOVER_PATH = "./logo/gameover.txt";
const char* const WIN_PATH = "./logo/win.txt";

enum Direction { D_UP, D_DOWN, D_LEFT, D_RIGHT };
enum Mode { 
	M_EASY = 30, 
	M_NORMAL = 10, 
	M_HARD = 10 
};

/* 获取标准输出句柄 */
HANDLE GetStdOHdl();

/* 设置标准输出位置 */
void SetConsolePosition(COORD pos);

/* (编译期)生成全为C的宽字符数组 */
template <size_t N>
struct CharArrayN : CharArrayN<N - 1> {
	constexpr CharArrayN(const wchar_t C) : CharArrayN<N - 1>(C), c(C) {}
	wchar_t c;
};
template <>
struct CharArrayN<0> {
	constexpr CharArrayN(const wchar_t C) {}
};

/* (编译期)生成全为C的宽字符串 */
template <size_t N>
struct StringN : CharArrayN<N> {
	constexpr StringN(const wchar_t C) :CharArrayN<N>(C), c(0) {}
	wchar_t c;
};

/* 获取对应的宽字符串 */
template<size_t N>
constexpr const wchar_t* GetStringN(wchar_t c) {
	const auto s = StringN<N>(c);
	return reinterpret_cast<const wchar_t*>(&s);
}

/* 仿函数，产生ab之间的随机整数 */
class RandomInt {
public:
	RandomInt() {
		srand((unsigned)time(NULL));
	}
	int operator()(int a, int b) {
		return (rand() % (b - a + 1)) + a;
	}
};

/* 判断两个矩形是否相交 */
bool IsHit(COORD pos1, int wx1, int wy1, COORD pos2, int wx2, int wy2);

bool IsSamePos(COORD pos1, COORD pos2);

/* 绘制字符文件 */
void DrawTitle(COORD pos, std::string file);

/* 设置控制台字符大小 */
void SetFontSize(int x);
