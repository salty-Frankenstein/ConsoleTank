#include"sprite.h"

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