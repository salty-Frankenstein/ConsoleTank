#include"background.h"
using namespace std;

void Background::Show() {
	//update showing score
}

void Background::Update() {

}

void Background::Draw() {
	wcout << GetStringN<GRID_X>(L'█') << endl;
	COORD pos{ 0, 1 };
	for (int i = 1; i <= GRID_Y - 2; i++) {
		SetConsolePosition(pos);
		wcout << L'█';
		pos.Y++;
	}
	pos.X = (GRID_X - 1) * 2;
	pos.Y = 1;
	for (int i = 1; i <= GRID_Y - 2; i++) {
		SetConsolePosition(pos);
		wcout << L'█' << endl;
		pos.Y++;
	}
	wcout << GetStringN<GRID_X>(L'█') << endl;

	for (int i = 0; i < GRID_X; i++) {
		bufferHdl->Push(make_shared<IronWall>(i * 2, 0));
		bufferHdl->Push(make_shared<IronWall>(i * 2, GRID_Y - 1));
	}

	for (int i = 1; i <= GRID_Y - 2; i++) {
		bufferHdl->Push(make_shared<IronWall>(0, i));
		bufferHdl->Push(make_shared<IronWall>((GRID_X - 1) * 2, i));
	}

	ifstream fin(L"logo.txt");
	pos.X = (GRID_X + 1) * 2;
	pos.Y = GRID_Y - 20;
	while (!fin.eof()) {
		SetConsolePosition(pos);
		string s;
		getline(fin, s);
		cout << s << endl;
		pos.Y++;
	}

}
