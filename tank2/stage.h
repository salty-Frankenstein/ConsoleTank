#pragma once
#include "gameobject.h"
#include<string>
#include<fstream>
#include<list>

class Stage {
public:
	Stage(int no, Mode mode);
	void Run();
private:
	void LoadStage(int no);
	void AddEnemy();
	std::shared_ptr<Number> score;
	std::shared_ptr<Number> playerNum;
	std::list<COORD> enemyPoint;
	Buffer buf;
	Mode mode;
};
