#pragma once
#include<list>
#include<memory>

class Sprite {
public:
	Sprite(int layer = 0);
	virtual void Update() = 0;
	virtual void Show() = 0;
	int GetLayer()const;
protected:
	int layer;
};

class Buffer {
public:
	void Update();
	void Show();
	void Push(std::shared_ptr<Sprite> s);
	void Sort();
private:
	std::list<std::shared_ptr<Sprite>> spriteList;
};


