#pragma once
#include "gameobject.h"

typedef unsigned long long GameTime;

class Game {
public:
	Game();
	void Run();
	static GameTime GetGameTime();
private:
	Buffer buf;
	HANDLE stdoutHdl;
	static GameTime gameTime;
};
