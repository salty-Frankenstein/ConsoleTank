#include"menu.h"
#include"game.h"
using namespace std;

Menu::Menu() {
	buttons[M_GAMESTART] = make_shared<Button>(35, 20, "GAME START");
	buttons[M_EXIT] = make_shared<Button>(35, 24, "EXIT");
	for (int i = 0; i < BUTTON_NUM; i++)
		buf.Push(buttons[i]);
	nowActive = 0;
}

void Menu::Run() {
	SetFontSize(20);
	system("cls");
	DrawTitle({ 10,2 }, LOGO_PATH);
	while (Game::state == G_MENU) {
		for (int i = 0; i < BUTTON_NUM; i++)
			if (i == nowActive)buttons[i]->isActive = true;
			else buttons[i]->isActive = false;
		buf.Show();
		if (_kbhit()) {
			switch (_getch()) {
			case 72:nowActive = (nowActive + 1) % 2; break;
			case 80:nowActive = (nowActive + BUTTON_NUM - 1) % 2; break;
			case 'z':
				switch (MenuButton(nowActive)) {
				case M_GAMESTART:Game::state = G_GAME; break;
				case M_EXIT:Game::state = G_EXIT; break;
				}
				break;
			default: break;
			}
		}
	}
}
