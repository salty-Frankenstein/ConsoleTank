#include"enemytank.h"
#include"game.h"
using namespace std;

const wchar_t EnemyTank::image[WIDTH_X][WIDTH_Y] = {
{ L'　',L'█',L'　' },
{ L'█',L'█',L'█' },
{ L'█',L'卐',L'█' }
};

EnemyTank::EnemyTank(int x, int y, int hp, int damage, int speed)
	: TankBase(S_ENEMY, WIDTH_X, WIDTH_Y, x, y, hp, damage, speed) {}

void EnemyTank::DrawTank() {
	auto pos = posCur;
	for (int i = 0; i < WIDTH_Y; i++) {
		SetConsoleCursorPosition(GetStdOHdl(), pos);
		pos.Y++;
		for (int j = 0; j < WIDTH_X; j++) {
			switch (dirCur) {
			case D_UP:
				wcout << (image[i][j]);
				break;
			case D_DOWN:
				wcout << (image[WIDTH_Y - i - 1][j]);
				break;
			case D_LEFT:
				wcout << (image[j][i]);
				break;
			case D_RIGHT:
				wcout << (image[WIDTH_X - j - 1][i]);
				break;
			}
		}
	}
}

/* 坦克移动AI */
void EnemyTank::Update() {
	static RandomInt randomInt;

	if (hp <= 0) {
		del = true;
		Clean();
	}
	
	/* 控制速度 */
	if (Game::GetGameTime() % (speed*10) != 0)return;

	posLast = posCur;
	dirLast = dirCur;
	switch (randomInt(1, 8)) {
	case 1:dirCur = D_UP; break;
	case 2:dirCur = D_LEFT; break;
	case 3:dirCur = D_RIGHT; break;
	case 4:dirCur = D_DOWN; break;
	default:GoStraight(); break;
	}

	if (randomInt(1, 10) == 1) {
		auto bulPos = posCur;
		switch (dirCur) {
		case D_UP:bulPos.X += 2; bulPos.Y--; break;
		case D_DOWN:bulPos.X += 2; bulPos.Y += 3; break;
		case D_LEFT:bulPos.X -= 2; bulPos.Y++; break;
		case D_RIGHT:bulPos.X += 6; bulPos.Y++; break;
		}
		bufferHdl->Push(make_shared<Bullet>(S_ENEMY_BULLET, bulPos.X, bulPos.Y, dirCur));
	}
}

inline void EnemyTank::GoStraight() {
	switch (dirCur) {
	case D_UP:posCur.Y--; break;
	case D_DOWN:posCur.Y++; break;
	case D_LEFT:posCur.X -= 2; break;
	case D_RIGHT:posCur.X += 2; break;
	}
}
