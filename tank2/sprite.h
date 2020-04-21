#pragma once
#include<list>
#include<memory>
#include<functional>
#include <windows.h>

class Buffer;

enum SpriteType { S_PLAYER, S_ENEMY, S_PLAYER_BULLET, S_ENEMY_BULLET, S_DESTORYABLE, S_OTHER };

class Sprite {
public:
	Sprite(int x = 0, int y = 0, int layer = 0, SpriteType type = S_OTHER);
	virtual void Update() = 0;
	virtual void Show() = 0;
	int GetLayer()const;
	SpriteType GetType()const;
	COORD GetPos()const;
	bool del;
	static Buffer* bufferHdl;	//游戏对象池句柄，实现与其它对象的消息传递
protected:
	int layer;
	COORD posCur;
	SpriteType type;
};

class Buffer {
public:
	void Update();
	void Show();
	void Push(std::shared_ptr<Sprite> s);
	void Sort();
	int Size()const;
	/* Any: 传入条件函数，如果buffer中存在元素满足，返回指针，否则返回nullptr */
	std::shared_ptr<Sprite> Any(std::function<bool(std::shared_ptr<Sprite>)>);
	/* Map: 功能同函数式对列表的map */
	void Map(std::function<void(std::shared_ptr<Sprite>)>map,
		std::function<bool(std::shared_ptr<Sprite>)> cond = 
		[](std::shared_ptr<Sprite>) {return true; }
	);
private:
	std::list<std::shared_ptr<Sprite>> spriteList;
};


