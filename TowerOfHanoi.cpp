#include "graphics.h"
#include <cmath>

using namespace std;

const int WIN_WIDTH = 1024;
const int WIN_HEIGHT = 768;

const int rx = round(WIN_HEIGHT / 4)
const int r1x = rx * 1;
const int r2x = rx * 2;
const int r3x = rx * 3;

const int ry1 = round(WIN_WIDTH * 0.25);
const int ry2 = round(WIN_WIDTH);

const int rr = 10


const int P4R = 75;
const int P3R = 50;
const int P2R = 25;
const int P1R = 12;


int board[3][5] =	{{0, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0},
					 {0, 0, 0, 0, 0}};
int placemarker[3] = {0, 0, 0}

#if defined(__UNIX__) || defined(linux)
	char CLEAR_SCREEN[] = "clear";
#elif defined(_WIN32) || defined(WIN32)
	char CLEAR_SCREEN[] = "cls";

//PPD END

void clear() {
	cleardevice();
	system(CLEAR_SCREEN);
}

bool pHasWon() {
	return placemarker[1] == 4 || placemarker[2] == 4;
}

void doTurn(int &turn) {

	turn++;
}

void drawScreen() {
	clear();

	//RODS
	setcolor(GREY);
	//rod 1
	bar(r1x - rr, ry1, r1x + rr, ry2);
	//rod 2
	bar(r2x - rr, ry1, r2x + rr, ry2);
	//rod 3
	bar(r3x - rr, ry1, r3x + rr, ry2);

	//4 PEICE
	for(int o = 0; o < sizeof(board); o++)
		for(int i = 0; i < sizeof(board[o]); i++)
			if(board[o][i] == 4) {
				bar(
					rx * o - P4R,
					WIN_HEIGHT - (25 * (o + 1)),
					rx * o + P4R,
					WIN_HEIGHT - (25 * o));
			}

	for(int o = 0; o < sizeof(board); o++)
		for(int i = 0; i < sizeof(board[o]); i++)
			if(board[o][i] == 3) {
				bar(
					rx * o - P3R,
					WIN_HEIGHT - (25 * (o + 1)),
					rx * o + P3R,
					WIN_HEIGHT - (25 * o));
			}

	for(int o = 0; o < sizeof(board); o++)
		for(int i = 0; i < sizeof(board[o]); i++)
			if(board[o][i] == 2) {
				bar(
					rx * o - P2R,
					WIN_HEIGHT - (25 * (o + 1)),
					rx * o + P2R,
					WIN_HEIGHT - (25 * o));
			}

	for(int o = 0; o < sizeof(board); o++)
		for(int i = 0; i < sizeof(board[o]); i++)
			if(board[o][i] == 1) {
				bar(
					rx * o - P1R,
					WIN_HEIGHT - (25 * (o + 1)),
					rx * o + P1R,
					WIN_HEIGHT - (25 * o));
			}

}

void setUpBoard() {
	board[0][0] = 4;
	board[0][1] = 3;
	board[0][2] = 2;
	board[0][3] = 1;
}

int main() {
	int turn;

	//INIT SCREEN
	initwindow(WIN_WIDTH, WIN_HEIGHT);

	system(CLEAR_SCREEN);
	setUpBoard();

	do {
		drawScreen();
		doTurn(turn);
	} while(!pHasWon());

	cout << "You beat the game in " << turns << " moves" << endl;
	return 0;
}
