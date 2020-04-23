#pragma once
#include "gameobject.h"
#include "stage.h"
typedef unsigned long long GameTime;

enum GameState { G_MENU, G_GAME, G_HISCORE, G_EXIT };

/* 游戏主流程控制 */
class Game {
public:
	Game();
	void Run();
	static GameTime GetGameTime();
	static void AddGameTime();
	static int player;
private:
	std::shared_ptr<Stage> stagePtr;
	//Number score;
	//Number playerNum;
	//Buffer buf;
	static GameTime gameTime;
};
