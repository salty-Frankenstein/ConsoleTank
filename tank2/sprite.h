#pragma once
#include<list>
#include<memory>

class Sprite {
public:
	virtual void Update() = 0;
	virtual void Show() = 0;
};

class Buffer {
public:
	void Update();
	void Show();
	void Push(std::shared_ptr<Sprite> s);
private:
	std::list<std::shared_ptr<Sprite>> spriteList;
};


