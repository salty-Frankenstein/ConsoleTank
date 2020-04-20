#include"playertank.h"
using namespace std;
const wchar_t PlayerTank::image[PLAYERTANK_X][PLAYERTANK_Y] = {
	{ L'　',L'█',L'　' },
{ L'█',L'█',L'█' },
{ L'█',L'★',L'█' }
};

PlayerTank::PlayerTank() 
	:TankBase(
		PLAYERTANK_X, PLAYERTANK_Y,
		10, 10,
		PLAYERTANK_HP,
		PLAYERTANK_DAMAGE,
		PLAYERTANK_SPEED) {}

inline void PlayerTank::DrawTank() {
	auto pos = posCur;
	for (int i = 0; i < PLAYERTANK_Y; i++) {
		SetConsoleCursorPosition(GetStdOHdl(), pos);
		pos.Y++;
		for (int j = 0; j < PLAYERTANK_X; j++) {
			switch (dirCur) {
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
	dirLast = dirCur;
	//auto c = getchar();
	//if (c == 'w')posCur.X++;
	if (_kbhit()) {
		switch (_getch()) {
		case 72:
			if (posCur.Y > 1)posCur.Y--;
			dirCur = D_UP;
			break;
		case 75:
			if (posCur.X > 2)posCur.X -= 2;
			dirCur = D_LEFT;
			break;
		case 77:
			if (posCur.X < 2 * (GRID_X - PLAYERTANK_X - 1))posCur.X += 2;
			dirCur = D_RIGHT;
			break;
		case 80:
			if (posCur.Y < GRID_Y - PLAYERTANK_Y - 1)posCur.Y++;
			dirCur = D_DOWN;
			break;
		default: break;
		}
	}
}
