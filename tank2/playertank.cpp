#include"playertank.h"
using namespace std;
const wchar_t PlayerTank::image[PLAYERTANK_X][PLAYERTANK_Y] = {
	{ L'　',L'█',L'　' },
{ L'█',L'█',L'█' },
{ L'█',L'★',L'█' }
};

PlayerTank::PlayerTank() 
	:TankBase(
		S_PLAYER,
		PLAYERTANK_X, PLAYERTANK_Y,
		40, 40,
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
	if (hp <= 0)del = true;
	posLast = posCur;
	dirLast = dirCur;
	//auto c = getchar();
	//if (c == 'w')posCur.X++;
	
	//system("pause");
	auto bulPos = posCur;
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
		case 'z':	//发射子弹
			switch (dirCur){
			case D_UP:bulPos.X += 2; bulPos.Y--;break;
			case D_DOWN:bulPos.X += 2; bulPos.Y += 3; break;
			case D_LEFT:bulPos.X -= 2; bulPos.Y++; break;
			case D_RIGHT:bulPos.X += 6; bulPos.Y++; break;
			}
			bufferHdl->Push(make_shared<Bullet>(S_PLAYER_BULLET, bulPos.X, bulPos.Y, dirCur));
			break;
		default: break;
		}
	}
}
