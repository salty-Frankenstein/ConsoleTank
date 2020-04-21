#include"sprite.h"

Buffer* Sprite::bufferHdl = nullptr;

Sprite::Sprite(int _layer, SpriteType _type) {
	layer = _layer;
	type = _type;
	del = false;
}

int Sprite::GetLayer()const {
	return layer;
}

SpriteType Sprite::GetType()const {
	return type;
}

void Buffer::Show() {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		(*i)->Show();
}

void Buffer::Update() {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		(*i)->Update();
	spriteList.remove_if(
		[](std::shared_ptr<Sprite> x) -> bool {return x->del; }
	);
}

void Buffer::Push(std::shared_ptr<Sprite> s) {
	spriteList.push_back(s);
}

void Buffer::Sort() {
	spriteList.sort(
		[](std::shared_ptr<Sprite> &a, std::shared_ptr<Sprite> &b) {
			return a->GetLayer() < b->GetLayer();
		}
	);
}

int Buffer::Size()const {
	return spriteList.size();
}

std::shared_ptr<Sprite> Buffer::Any(std::function<bool(std::shared_ptr<Sprite>)> f) {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		if (f(*i))return *i;
	return nullptr;
}

void Buffer::Map(std::function<void(std::shared_ptr<Sprite>)> map,
	std::function<bool(std::shared_ptr<Sprite>)> cond) {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		if (cond(*i))map(*i);
}
