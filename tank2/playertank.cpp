#include"playertank.h"
using namespace std;
const wchar_t PlayerTank::image[PLAYERTANK_X][PLAYERTANK_Y] = {
	{ L'　',L'█',L'　' },
{ L'█',L'█',L'█' },
{ L'█',L'★',L'█' }
};

PlayerTank::PlayerTank() :TankBase(3, 3, 10, 10) {}

inline void PlayerTank::DrawTank() {
	auto pos = posCur;
	for (int i = 0; i < PLAYERTANK_Y; i++) {
		SetConsoleCursorPosition(GetStdOHdl(), pos);
		pos.Y++;
		for (int j = 0; j < PLAYERTANK_X; j++) {
			switch (direction) {
			case D_UP:
				wcout << (image[i][j]);
				break;
			case D_DOWN:
				wcout << (image[PLAYERTANK_Y - i - 1][j]);
				break;
			case D_LEFT:
				wcout << (image[j][i]);
				break;
			case D_RIGHT:
				wcout << (image[PLAYERTANK_X - j - 1][i]);
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
