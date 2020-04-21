#include"bullet.h"
#include"tankbase.h"
using namespace std;
Bullet::Bullet(SpriteType type, int _x, int _y, Direction _dir)
	:Sprite(_x, _y, LAYER_BULLET, type) {
	dir = _dir;
	posCur.X = posLast.X = _x;
	posCur.Y = posLast.Y = _y;
}

void Bullet::Update() {
	/* 飞出屏幕 */
	if (posCur.X >= (GRID_X-3)*2 || posCur.Y >= GRID_Y -2 || posCur.X <= 2 || posCur.Y <= 1) {
		del = true;
		SetConsoleCursorPosition(GetStdOHdl(), posCur);
		wcout << L'　';
	}
	/* 击中目标 */
	auto isEnemy = [=](shared_ptr<Sprite> s) -> bool {
		if (s->GetType() == S_DESTORYABLE)return true;
		if (this->GetType() == S_ENEMY_BULLET) {
			if (s->GetType() == S_PLAYER)return true;
			return false;
		}
		if (s->GetType() == S_ENEMY)return true;
		return false;
	};

	auto isHit = [=](shared_ptr<Sprite> s)->bool {
		switch (s->GetType()) {
		case S_ENEMY_BULLET:
			return IsHit(this->GetPos(), 1, 1, s->GetPos(), 1, 1);
		case S_ENEMY:
		case S_PLAYER:
			auto t = static_cast<TankBase*>(s.get());
			return IsHit(this->GetPos(), 1, 1, t->GetPos(), t->GetWidthX(), t->GetWidthY());
		}
	};

	auto res = bufferHdl->Any(
		[=](shared_ptr<Sprite> s) -> bool {
			return isEnemy(s) && isHit(s);
		}
	);

	if (res != nullptr) {
		switch (res->GetType()) {
		case S_PLAYER:
		case S_ENEMY:
			static_cast<TankBase*>(res.get())->GetDamage(1);
		default:
			break;
		}
	}

	/* 移动 */
	posLast = posCur;
	switch (dir) {
	case D_UP:posCur.Y--; break;
	case D_DOWN:posCur.Y++; break;
	case D_LEFT:posCur.X -= 2; break;
	case D_RIGHT:posCur.X += 2; break;
	}
	
}

void Bullet::Show() {
	SetConsoleCursorPosition(GetStdOHdl(), posLast);
	wcout << L'　';
	SetConsoleCursorPosition(GetStdOHdl(), posCur);
	wcout << image;
}
