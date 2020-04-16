#define _CRT_SECURE_NO_WARNINGS
#include "gameobject.h"
using namespace std;

int main() {
	Buffer buf;
	buf.Push(make_shared<PlayerTank>());
	while (1) {
		buf.Show();
		buf.Update();
		Sleep(30);
	}
	return 0;
}