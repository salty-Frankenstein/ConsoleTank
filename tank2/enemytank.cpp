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
	switch (hp) {
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		break;
	}
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/* 坦克移动AI */
void EnemyTank::Update() {
	static RandomInt randomInt;

	if (hp <= 0) {
		Delete();
	}
	
	/* 控制速度 */
	if (Game::GetGameTime() % (20 - speed) != 0)return;

	posLast = posCur;
	dirLast = dirCur;
	
	switch (randomInt(1, 20)) {
	case 1:dirCur = D_UP; break;
	case 2:dirCur = D_LEFT; break;
	case 3:dirCur = D_RIGHT; break;
	case 4:dirCur = D_DOWN; break;
	default:GoStraight(); break;
	}

	if (!IsSamePos(posCur, posLast)) {
		auto res = bufferHdl->Any(
			[=](shared_ptr<Sprite> s)->bool {
			if (IsBarrier(s->GetType()) &&
				IsHit(this->GetPos(), 3, 3, s->GetPos(), 1, 1))
				return true;
			if ((s->GetType() == S_PLAYER || s->GetType() == S_ENEMY && s.get() != this)
				&& IsHit(this->GetPos(), 3, 3, s->GetPos(), 3, 3))
				return true;
			return false;
		}
		);
		if (res != nullptr) {
			posCur = posLast;
		}
	}

	if (randomInt(1, 4) == 1) {
		auto bulPos = posCur;
		switch (dirCur) {
		case D_UP:bulPos.X += 2; break;
		case D_DOWN:bulPos.X += 2; bulPos.Y += 2; break;
		case D_LEFT: bulPos.Y++; break;
		case D_RIGHT:bulPos.X += 4; bulPos.Y++; break;
		}
		if (bufferHdl->Any([=](shared_ptr<Sprite> s) {return IsSamePos(bulPos, s->GetPos()); }) == nullptr)
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
