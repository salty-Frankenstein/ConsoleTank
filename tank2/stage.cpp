#include"stage.h"
#include"game.h"
using namespace std;

Stage::Stage(int no, Mode _mode) {
	Sprite::bufferHdl = &buf;
	score = make_shared<Number>(GRID_X * 2 + 10, 2, 5);
	playerNum = make_shared<Number>((GRID_X + 11) * 2, GRID_Y - 30, 2);
	buf.Push(score);
	buf.Push(playerNum);
	LoadStage(no);
	mode = _mode;
}

void Stage::Run() {
	system("cls");
	//buf.Push(make_shared<PlayerTank>());
	/*
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<LightTank>(16 + i * 16, 2 + j * 16));
			else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 2; j++)
			if (j == 1)buf.Push(make_shared<AntiTankGun>(16 + i * 16, 2 + j * 16 - 5));
			//else buf.Push(make_shared<ArmoredCar>(16 + i * 16, 2 + j * 16));
*/
	shared_ptr<Background> bg = make_shared<Background>();
	bg->Draw();
	buf.Push(bg);

	while (1) {
		score->SetNumber(buf.Size());
		//score->SetNumber(Game::GetGameTime());
		playerNum->SetNumber(Game::player);

		AddEnemy();
		buf.Sort();
		buf.Show();
		buf.Update();
		Sleep(30);
		Game::AddGameTime();
	}

}

void Stage::LoadStage(int no) {
	string file = "./stage/" + to_string(no) + ".txt";
	ifstream fin(file);
	string s;
	getline(fin, s);
	for (SHORT i = 1; i <= GRID_Y-2; i++) {
		getline(fin, s);
		for (SHORT j = 1; j <= GRID_X - 2; j++) {
			switch (s[j]) {
			case '#':
				buf.Push(make_shared<BrickWall>(2 * j, i));
				break;
			case '=':
				buf.Push(make_shared<IronWall>(2 * j, i));
				break;
			case 'P':
				buf.Push(make_shared<PlayerTank>(2 * j, i));
				break;
			case 'E':
				enemyPoint.push_back({ 2 * j, i });
				break;
			default:
				break;
			}
		}
	}
}

void Stage::AddEnemy() {
	static RandomInt randomInt;
	for (auto i = enemyPoint.begin(); i != enemyPoint.end(); i++) {
		if (Game::GetGameTime() % 10 == 0 && randomInt(1, mode) == 1 
			&& buf.Any([=](shared_ptr<Sprite> s) { return IsTank(s) && IsHit(*i, 3, 3, s->GetPos(), 3, 3); }) == nullptr) {
			switch (randomInt(1,4)) {
			case 1:buf.Push(make_shared<LightTank>(i->X, i->Y)); break;
			case 2:buf.Push(make_shared<ArmoredCar>(i->X, i->Y)); break;
			case 3:buf.Push(make_shared<HeavyTank>(i->X, i->Y)); break;
			case 4:buf.Push(make_shared<AntiTankGun>(i->X, i->Y)); break;
			}
		}
	}
}
