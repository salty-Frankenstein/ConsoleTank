#pragma once
#include "gameobject.h"

class Stage {
public:
	Stage(int no);
	void Run();
private:
	std::shared_ptr<Number> score;
	std::shared_ptr<Number> playerNum;
	Buffer buf;
};
