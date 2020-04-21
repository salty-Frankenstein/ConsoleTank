#pragma once
#include "gameobject.h"

typedef unsigned long long GameTime;

/* 游戏主流程控制 */
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
