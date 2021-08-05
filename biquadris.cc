#include "biquadris.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "level.h"
#include <memory>
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() {
	player1.init();
	player2.init();
}

void Biquadris::playGame() {
	bool fp = true;
	string cmd;
	char bType;
	Level *level_fp;
	Level *level_sp;

	if (in_file) {
		level_fp = new Level0(seq_1);
		level_sp = new Level0(seq_2);
	} else {
		std::cout << "Choose you level [1-4]" << std::endl;
		cin >> level;

		if (level == 1) {
			level_fp = new Level1;
			level_sp = new Level1;
		} else if (level == 2) {
			level_fp = new Level2;
			level_sp = new Level2;
		} else if (level == 3) {
			level_fp = new Level3;
			level_sp = new Level3;
		} else {
			level_fp = new Level4;
			level_sp = new Level4;
		}
	}



	cout << "PLAYING" << endl;

	while (true) {
		if (fp) {
			bType = level_fp->makeBlock();
			cout << "PLAYER 1: " << endl;
		} else {
			bType = level_sp->makeBlock();
			cout << "PLAYER 2: " << endl;
		}

		cout << "TYPE: " << bType << endl;

		if (bType == 'I') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'J') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'L') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'O') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'Z') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'S') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'T') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, 0, player1);
			} else {
				curBlock = make_unique<IBlock>(0, 0, player2);
			}
			curBlock->placeBlock();
		}
		if (fp) {
			player1.printBoard();
		} else {
			player2.printBoard();
		}
		while (cin >> cmd) {
			if (cmd == "left") {
				curBlock->move(-1, 0);
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "right") {
				curBlock->move(1, 0);
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}

			} else if (cmd == "down") {
				curBlock->move(0, 1);
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}

			} else if (cmd == "clockwise") {
				curBlock->rotateCW();
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}

			} else if (cmd == "counterclockwise") {
				curBlock->rotateCCW();
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}

			} else if (cmd == "drop") {
				curBlock->drop();
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
				fp = !fp;
				break;
			}
		}
	}
}







