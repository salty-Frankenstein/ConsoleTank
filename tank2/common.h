/*
	共用的常量、函数
*/
#pragma once
#include <windows.h>
#include <conio.h>
#include <ctime>
const int GRID_X = 60;
const int GRID_Y = 60;

enum Direction { D_UP, D_DOWN, D_LEFT, D_RIGHT };

HANDLE GetStdOHdl();

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
