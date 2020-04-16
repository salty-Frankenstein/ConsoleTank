#include"playertank.h"
using namespace std;
const wchar_t PlayerTank::image[LENGTH][WIDTH] = {
	{ L'　',L'█',L'　' },
{ L'█',L'█',L'█' },
{ L'█',L'★',L'█' }
};

PlayerTank::PlayerTank() :TankBase(3, 3, 10, 10) {}

inline void PlayerTank::DrawTank() {
	auto pos = posCur;
	for (int i = 0; i < LENGTH; i++) {
		SetConsoleCursorPosition(stdoutHdl, pos);
		pos.Y++;
		for (int j = 0; j < WIDTH; j++) {
			switch (direction) {
			case D_UP:
				wcout << (image[i][j]);
				break;
			case D_DOWN:
				wcout << (image[LENGTH - i - 1][j]);
				break;
			case D_LEFT:
				wcout << (image[j][i]);
				break;
			case D_RIGHT:
				wcout << (image[WIDTH - j - 1][i]);
				break;
			}
		}
	}
}

inline void PlayerTank::Update() {
	posLast = posCur;
	//auto c = getchar();
	//if (c == 'w')posCur.X++;
	if (_kbhit()) {
		switch (_getch()) {
		case 72:
			posCur.Y--;
			direction = D_UP;
			break;
		case 75:
			posCur.X-=2;
			direction = D_LEFT;
			break;
		case 77:
			posCur.X+=2;
			direction = D_RIGHT;
			break;
		case 80:
			posCur.Y++;
			direction = D_DOWN;
			break;
		default: break;
		}
	}
}
