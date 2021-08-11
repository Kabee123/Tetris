#include "biquadris.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() : hiScore{0} {
	player1.init();
	player2.init();
	boards.emplace_back(&player1);
	boards.emplace_back(&player2);
}

void Biquadris::playGame() {
	//std::srand(std::time (NULL));
	bool fp = true; //fp = 1 and !fp = 0
	string cmd;
	char bType;
	Level *level_fp;
	Level *level_sp;

	int lvl;
	int blk;

	if (in_file) {
		level_fp = new Level0(seq_1);
		level_sp = new Level0(seq_2);
	} else {
		std::cout << "Choose your level player 1 [1-4]" << std::endl;
		cin >> lvl;
		player1.setBoardLevel(lvl);
		if (player1.boardLevel() == 1) {
			level_fp = new Level1;
		} else if (player1.boardLevel() == 2) {
			level_fp = new Level2;
		} else if (player1.boardLevel() == 3) {
			level_fp = new Level3;
		} else {
			level_fp = new Level4;
		}

		std::cout << "Choose your level player 2 [1-4]" << std::endl;
		cin >> lvl;
		player2.setBoardLevel(lvl);
		if (player2.boardLevel() == 1) {
			level_sp = new Level1;
		} else if (player2.boardLevel() == 2) {
			level_sp = new Level2;
		} else if (player2.boardLevel() == 3) {
			level_sp = new Level3;
		} else {
			level_sp = new Level4;
		}
	}
	int turn = -1;
	while (true) {
		if (cin.eof()) {
			break;
		}

		if (fp) ++turn;	

		if (fp) {
			cout << "COUNTER: " << level_fp->counter << endl; //HERE
			if (level_fp->counter > 0 && level_fp->counter % 5 == 0) {
				cout << "TRIGGERED" << endl; //HERE
				player1.bomb();
			}
			if (player1.getForce()) {
				bType = player1.getForcedB();
				player1.setNextB(level_fp->makeBlock());
				player1.setForce(false);
			} else {
				if (player1.getNextB() == 'X') {
					bType = level_fp->makeBlock();
					player1.setNextB(level_fp->makeBlock());
				} else {
					bType = player1.getNextB();
					player1.setNextB(level_fp->makeBlock());
				}
			}
			//cout << "PLAYER 1: " << endl; //HERE
		} else {
			if (level_sp->counter > 0 && level_sp->counter % 5 == 0) {
				player2.bomb();
			}
			if (player2.getForce()) {
				bType = player2.getForcedB();
				player2.setNextB(level_fp->makeBlock());
				player2.setForce(false);
			} else {
				if (player2.getNextB() == 'X') {
					bType = level_fp->makeBlock();
					player2.setNextB(level_fp->makeBlock());
				} else {
					bType = player2.getNextB();
					player2.setNextB(level_fp->makeBlock());
				}
			}
			//cout << "PLAYER 2: " << endl; //HERE
		}

		if (bType == 'I') {
			curBlock = make_unique<IBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		} else if (bType == 'J') {
			curBlock = make_unique<JBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		} else if (bType == 'L') {
			curBlock = make_unique<LBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
 		} else if (bType == 'O') {
			curBlock = make_unique<OBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		} else if (bType == 'Z') {
			curBlock = make_unique<ZBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		} else if (bType == 'S') {
			curBlock = make_unique<SBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		} else if (bType == 'T') {
			curBlock = make_unique<TBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
		}

		if (!curBlock->placeBlock()) { // IDK
			cout << "YOU LOST" << endl;
			break;
		}

		//cout << "TYPE: " << bType << endl;
		//cout << "NEXT: " << boards[!fp]->getNextB() << endl;
				
		cout << boards;	

		while (cin >> cmd) {
			if (cmd == "left" or cmd == "right") {
				if (cmd == "left") {
					curBlock->move(-1, 0);
				} else if (cmd == "right") {
					curBlock->move(1, 0);
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				if (fp && player1.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						//player1.printBoard();
						player1.setHeavy(false);
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						//player1.printBoard();
						player1.setHeavy(false);
						break;
					}
				} else if (!fp && player2.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						//player2.printBoard();
						player2.setHeavy(false);
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						//player2.printBoard();
						player2.setHeavy(false);
						break;
					}
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "down") {
				curBlock->move(0, 1);
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "clockwise") {
				curBlock->rotateCW();
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "counterclockwise") {
				curBlock->rotateCCW();
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "drop") {
				int c_rows;
				curBlock->drop();
				curBlock->placeBlock();
				c_rows = boards[!fp]->checkRows();
				if (fp) {
					if (c_rows > 0) {
						boards[!fp]->setScore(pow(boards[!fp]->boardLevel() + c_rows, 2));
						level_fp->counter = 0;
					} 	
					if (c_rows > 1) {
						cout << "Choose your special action (blind, heavy, force)" << endl;
						cin >> cmd;
						if (cmd == "blind") {
							player2.setBlind(true);
						} else if (cmd == "heavy") {
							player2.setHeavy(true);
						} else {
							player2.setForce(true);
							cin >> blk;
							player2.setForcedB(blk);
						}
					}
				} else {
					if (c_rows > 0) {
						boards[!fp]->setScore(pow(boards[!fp]->boardLevel() + c_rows, 2));
						level_sp->counter = 0;
					} 
					if (c_rows > 1) {
						cout << "Choose your special action (blind, heavy, force)" << endl;
						cin >> cmd;
						if (cmd == "blind") {
							player1.setBlind(true);
						} else if (cmd == "heavy") {
							player1.setHeavy(true);
						} else {
							player1.setForce(true);
							cin >> blk;
							player1.setForcedB(blk);
						}
					}
				}
				cout << boards;
				fp = !fp;
				break;
			} else if (cmd == "levelup") {
				if (boards[!fp]->boardLevel() == 4) {
					continue;
				} else {
					boards[!fp]->setBoardLevel(boards[!fp]->boardLevel() + 1);
					cout << boards[!fp]->boardLevel() << endl;
				}

				if (fp) {
					/*if (player1.boardLevel() == 4) {
						continue;
					} else {
						player1.setBoardLevel(player1.boardLevel() + 1);
						cout << player1.boardLevel() << endl;
					}*/

					Level *temp = level_fp;
					delete temp;
					if (player1.boardLevel() == 1) {
						level_fp = new Level1;
					} else if (player1.boardLevel() == 2) {
						level_fp = new Level2;
					} else {
						level_fp = new Level3;
					}

				} else {
					/*if (player2.boardLevel() == 4) {
						continue;
					} else {
						player2.setBoardLevel(player2.boardLevel() + 1);
						cout << player2.boardLevel() << endl;
					}*/

					Level *temp = level_sp;
					delete temp;
					if (player2.boardLevel() == 1) {
						level_sp = new Level1;
					} else if (player2.boardLevel() == 2) {
						level_sp = new Level2;
					} else {
						level_sp = new Level3;
					}
				}
			} else if (cmd == "random") {
				if (fp) {
					level_fp->in_file = false;
				} else {
					level_sp->in_file = false;
				}
			} else if (cmd == "norandom") {
				if (fp) {
					cin >> level_fp->seq_file;
					level_fp->in_file = true;
				} else {
					cin >> level_sp->seq_file;
					level_sp->in_file = true;
				}
			} else if (cmd == "sequence") {
			//do something
			} else if (cmd == "I" or cmd == "J" or cmd == "L" or cmd == "O" or
					cmd == "S" or cmd == "Z" or cmd == "T") {

				int shiftx;
				int shifty;
				shiftx = curBlock->getBotL().x;
				shifty = curBlock->getBotL().y - 3;

				cout << "SHIFT" << shiftx << " " << shifty << endl;
				curBlock->clearBlock();

				if (cmd == "I") {
					curBlock = make_unique<IBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "J") {
					curBlock = make_unique<JBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "L") {
					curBlock = make_unique<LBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "O") {
					curBlock = make_unique<OBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "Z") {
					curBlock = make_unique<ZBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "S") {
					curBlock = make_unique<SBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				} else if (cmd == "T") {
					curBlock = make_unique<TBlock>(turn, boards[!fp]->boardLevel(), boards[!fp]);
				}
				curBlock->move(shiftx, shifty);	
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "restart") {
				restartGame();
				level_fp->counter = -1;
				level_sp->counter = -1;
				//player1.printBoard();

				//MORE RESETING
				cout << boards;
				break;
			}	
		}
	}
}

void Biquadris::restartGame() {
	player1.reset();
	player2.reset();
}


