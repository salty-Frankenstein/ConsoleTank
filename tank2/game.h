#pragma once
#include "gameobject.h"
#include "stage.h"
#include "menu.h"
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
	static int enemyNow;
	static int enemyMax;
	static int enemyKill;
	static bool playerAlive;
	static GameState state;
private:
	std::shared_ptr<Stage> stagePtr;
	Menu menu;
	static GameTime gameTime;
	const int MAX_STAGE = 1;
};
