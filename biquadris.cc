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
		Board cplayer;
		//      cout << "TYPE:" << curBlock->type << endl;
		if (fp) {
			bType = level_fp->makeBlock();
			cplayer = player1;
		} else {
			bType = level_sp->makeBlock();
			cplayer = player2;
		}

		if (bType == 'I') {
			curBlock = make_unique<IBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'J') {
			curBlock = make_unique<JBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'L') {
			curBlock = make_unique<LBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'O') {
			curBlock = make_unique<OBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'Z') {
			curBlock = make_unique<ZBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'S') {
			curBlock = make_unique<SBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		} else if (bType == 'T') {
			curBlock = make_unique<TBlock>(0, 0, cplayer);
			curBlock->placeBlock();
		}
		cplayer.printBoard();
		while (cin >> cmd) {
			if (cmd == "left") {
				curBlock->move(-1, 0);
				curBlock->placeBlock();
				cplayer.printBoard();
			} else if (cmd == "right") {
				curBlock->move(1, 0);
				curBlock->placeBlock();
				cplayer.printBoard();
			} else if (cmd == "down") {
				curBlock->move(0, 1);
				curBlock->placeBlock();
				cplayer.printBoard();
			} else if (cmd == "clockwise") {
				curBlock->rotateCW();
				curBlock->placeBlock();
				cplayer.printBoard();
			} else if (cmd == "counterclockwise") {
				curBlock->rotateCCW();
				curBlock->placeBlock();
				cplayer.printBoard();
			} else if (cmd == "drop") {
				cout << "TRIGGER:" << endl;
				curBlock->drop();
				cout << "here" << endl;
				curBlock->placeBlock();
				cplayer.printBoard();
				fp = !fp;
				break;
			}
		}
	}
}







