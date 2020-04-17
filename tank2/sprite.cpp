#include"sprite.h"

Sprite::Sprite(int _layer) {
	layer = _layer;
}

int Sprite::GetLayer()const {
	return layer;
}

void Buffer::Show() {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		(*i)->Show();
}

void Buffer::Update() {
	for (auto i = spriteList.begin(); i != spriteList.end(); i++)
		(*i)->Update();
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
