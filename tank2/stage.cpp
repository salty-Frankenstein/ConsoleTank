#include"stage.h"
#include"game.h"
using namespace std;

Stage::Stage(int no) {
	Sprite::bufferHdl = &buf;
	score = make_shared<Number>(GRID_X * 2 + 10, 10, 5);
	playerNum = make_shared<Number>((GRID_X + 11) * 2, GRID_Y - 30, 2);
	buf.Push(score);
	buf.Push(playerNum);
}

void Stage::Run() {
	system("cls");
	buf.Push(make_shared<PlayerTank>());

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<LightTank>(16 + i * 16, 2 + j * 16));
			else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<AntiTankGun>(16 + i * 16, 2 + j * 16 - 5));
			//else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));

	shared_ptr<Background> bg = make_shared<Background>();
	bg->Draw();
	buf.Push(bg);

	for (int i = 1; i <= 45; i++)
		buf.Push(make_shared<IronWall>(2 * i + 6, 30));
	for (int i = 4; i <= 45; i++) {
		buf.Push(make_shared<BrickWall>(2 * i + 6, 40));
		buf.Push(make_shared<BrickWall>(2 * i + 6, 41));
		buf.Push(make_shared<BrickWall>(2 * i + 6, 42));
	}

	for (int i = 1; i <= 45; i++)
		buf.Push(make_shared<IronWall>(2 * i + 6, 50));

	while (1) {
		score->SetNumber(Game::GetGameTime());
		playerNum->SetNumber(Game::player);
		buf.Sort();
		buf.Show();
		buf.Update();
		Sleep(30);
		Game::AddGameTime();
	}

}
