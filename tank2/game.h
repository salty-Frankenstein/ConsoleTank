#pragma once
#include "gameobject.h"

class Game {
public:
	Game();
	void Run();
private:
	Buffer buf;
	HANDLE stdoutHdl;
};
