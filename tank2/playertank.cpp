#include"playertank.h"

const char PlayerTank::image[LENGTH][WIDTH] = {
{ ' ','#',' ' },
{ '#','#','#' },
{ '#','0','#' }
};

PlayerTank::PlayerTank() :TankBase(3, 3, 10, 10) {}

void PlayerTank::DrawTank() {
	auto pos = posCur;
	for (int i = 0; i < LENGTH; i++) {
		SetConsoleCursorPosition(stdoutPtr, pos);
		pos.Y++;
		for (int j = 0; j < WIDTH; j++) {
			switch (direction) {
			case D_UP:
				putchar(image[i][j]);
				break;
			case D_DOWN:
				putchar(image[LENGTH - i - 1][j]);
				break;
			case D_LEFT:
				putchar(image[j][i]);
				break;
			case D_RIGHT:
				putchar(image[WIDTH - j - 1][i]);
				break;
			}
		}
	}
}

void PlayerTank::Update() {
	posLast = posCur;
	//auto c = getchar();
	//if (c == 'w')posCur.X++;
	if (_kbhit()) {
		switch (_getch()) {
		case 72:
			posCur.Y--;
			direction = D_UP;
			break;
		case 75:
			posCur.X--;
			direction = D_LEFT;
			break;
		case 77:
			posCur.X++;
			direction = D_RIGHT;
			break;
		case 80:
			posCur.Y++;
			direction = D_DOWN;
			break;
		default: break;
		}
	}
}
