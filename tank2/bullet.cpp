#include"bullet.h"
#include"tankbase.h"
using namespace std;
Bullet::Bullet(SpriteType type, int _x, int _y, Direction _dir)
	:Sprite(_x, _y, LAYER_BULLET, type) {
	dir = _dir;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
}

void Bullet::Delete() {
	del = true;
	SetConsoleCursorPosition(GetStdOHdl(), posLast);
	wcout << L'　';
}

void Bullet::Update() {
	/* 移动 */
	posLast = posCur;
	switch (dir) {
	case D_UP:posCur.Y--; break;
	case D_DOWN:posCur.Y++; break;
	case D_LEFT:posCur.X -= 2; break;
	case D_RIGHT:posCur.X += 2; break;
	}

	/* 击中目标 */
	auto isEnemy = [=](shared_ptr<Sprite> s) -> bool {
		if (this->GetType() == S_ENEMY_BULLET) {
			switch (s->GetType()) {
			case S_DESTORYABLE:
			case S_UNDESTORYABLE:
			case S_PLAYER_BULLET:
			//case S_ENEMY:
			case S_PLAYER:
				return true;
			default:
				return false;
			}
		}
		else {
			switch (s->GetType()) {
			case S_DESTORYABLE:
			case S_UNDESTORYABLE:
			case S_ENEMY_BULLET:
			case S_ENEMY:
				return true;
			default:
				return false;
			}
		}
	};

	auto destoryableHit = [=](shared_ptr<Sprite> s) {
		if (s->GetType() != S_DESTORYABLE)return false;
		auto x = this->GetPos(), y = this->GetPos();
		switch (this->GetDirection()) {
		case D_UP:case D_DOWN:x.X -= 2; y.X += 2; break;
		case D_LEFT:case D_RIGHT:x.Y++; y.Y--; break;
		}
		return IsSamePos(this->GetPos(), s->GetPos())
			|| IsSamePos(x, s->GetPos())
			|| IsSamePos(y, s->GetPos());
	};

	auto isHit = [=](shared_ptr<Sprite> s)->bool {
		switch (s->GetType()) {
		case S_ENEMY_BULLET:
		case S_UNDESTORYABLE:
			return IsSamePos(this->GetPos(), s->GetPos());
		case S_DESTORYABLE:
			return destoryableHit(s);
		case S_ENEMY:
		case S_PLAYER:
			auto t = static_cast<TankBase*>(s.get());
			return IsHit(this->GetPos(), 1, 1, t->GetPos(), t->GetWidthX(), t->GetWidthY());
		}
		return false;
	};

	auto res = bufferHdl->Any(
		[=](shared_ptr<Sprite> s) -> bool {
			return isEnemy(s) && isHit(s);
		}
	);

	if (res != nullptr) {
		switch (res->GetType()) {
		case S_DESTORYABLE:
			bufferHdl->Map([](shared_ptr<Sprite> s) {s->Delete(); }, destoryableHit);
			break;
		case S_ENEMY_BULLET:
		case S_PLAYER_BULLET:
			res->Delete();
			break;
		case S_PLAYER:
		case S_ENEMY:
			static_cast<TankBase*>(res.get())->GetDamage(1);
		default:break;
		}
		Delete();
	}
}

void Bullet::Show() {
	if (del)return;
	if(type == S_PLAYER_BULLET)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	SetConsoleCursorPosition(GetStdOHdl(), posLast);
	wcout << L'　';
	SetConsoleCursorPosition(GetStdOHdl(), posCur);
	wcout << image;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

Direction Bullet::GetDirection()const {
	return dir;
}
