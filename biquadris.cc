#include "biquadris.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() {
	player1.init();
	player2.init();
}

void Biquadris::playGame() {
	std::srand(std::time (NULL));
	bool fp = true;
	string cmd;
	char bType;
	Level *level_fp;
	Level *level_sp;

	if (in_file) {
		level_fp = new Level0(seq_1);
		level_sp = new Level0(seq_2);
	} else {
		std::cout << "Choose your level player 1 [1-4]" << std::endl;
		cin >> player1.level;
		if (player1.level == 1) {
			level_fp = new Level1;
		} else if (player1.level == 2) {
			level_fp = new Level2;
		} else if (player1.level == 3) {
			level_fp = new Level3;
		} else {
			level_fp = new Level4;
		}

		std::cout << "Choose your level player 2 [1-4]" << std::endl;
		cin >> player2.level;
		if (player2.level == 1) {
			level_sp = new Level1;
		} else if (player2.level == 2) {
			level_sp = new Level2;
		} else if (player2.level == 3) {
			level_sp = new Level3;
		} else {
			level_sp = new Level4;
		}
	}

	while (true) {
		if (cin.eof()) {
			break;
		}

		if (fp) {
			cout << "COUNTER: " << level_fp->counter << endl;
			if (level_fp->counter > 0 && level_fp->counter % 5 == 0) {
				cout << "TRIGGERED" << endl;
				player1.bomb();
			}
			if (player1.force) {
				bType = player1.forced;
				player1.nextBlock = level_fp->makeBlock();
				player1.force = false;
			} else {
				if (player1.nextBlock == 'X') {
					bType = level_fp->makeBlock();
					player1.nextBlock = level_fp->makeBlock();
				} else {
					bType = player1.nextBlock;
					player1.nextBlock = level_fp->makeBlock();
				}
			}
			cout << "PLAYER 1: " << endl;
		} else {
			if (level_sp->counter > 0 && level_sp->counter % 5 == 0) {
				player2.bomb();
			}
			if (player2.force) {
				bType = player2.forced;
				player2.nextBlock = level_sp->makeBlock();
				player2.force = false;
			} else {
				if (player1.nextBlock == 'X') {
					bType = level_fp->makeBlock();
					player1.nextBlock = level_fp->makeBlock();
				} else {
					bType = player1.nextBlock;
					player1.nextBlock = level_fp->makeBlock();
				}
			}
			cout << "PLAYER 2: " << endl;
		}

		if (bType == 'I') {
			if (fp) {
				curBlock = make_unique<IBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<IBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'J') {
			if (fp) {
				curBlock = make_unique<JBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<JBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'L') {
			if (fp) {
				curBlock = make_unique<LBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<LBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'O') {
			if (fp) {
				curBlock = make_unique<OBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<OBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'Z') {
			if (fp) {
				curBlock = make_unique<ZBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<ZBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'S') {
			if (fp) {
				curBlock = make_unique<SBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<SBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		} else if (bType == 'T') {
			if (fp) {
				curBlock = make_unique<TBlock>(0, player1.level, player1);
			} else {
				curBlock = make_unique<TBlock>(0, player2.level, player2);
			}
			curBlock->placeBlock();
		}
		cout << "TYPE: " << bType << endl;
		cout << "NEXT: " << player1.nextBlock << endl;

		if (fp) {
			player1.printBoard();
		} else {
			player2.printBoard();
		}
		while (cin >> cmd) {
			if (cmd == "left") {
				curBlock->move(-1, 0);
				if (curBlock->levelMade >= 3) {
					curBlock->move(0, 1);
				}
				if (fp && player1.heavy) {
					if (!curBlock->move(0, 1)) {
						player1.printBoard();
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player1.printBoard();
						break;
					}
				} else if (!fp && player2.heavy) {
					if (!curBlock->move(0, 1)) {
						player2.printBoard();
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player2.printBoard();
						break;
					}
				}
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "right") {
				curBlock->move(1, 0);
				if (curBlock->levelMade >= 3) {
					curBlock->move(0, 1);
				}
				if (fp && player1.heavy) {
					if (!curBlock->move(0, 1)) {
						player1.printBoard();
						player1.heavy = false;
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player1.printBoard();
						player1.heavy = false;
						break;
					}
				} else if (!fp && player2.heavy) {
					if (!curBlock->move(0, 1)) {
						player2.printBoard();
						player2.heavy = false;
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player2.printBoard();
						player2.heavy = false;
						break;
					}
				}
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "down") {
				curBlock->move(0, 1);
				if (curBlock->levelMade >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "clockwise") {
				curBlock->rotateCW();
				if (curBlock->levelMade == 3 || curBlock->levelMade == 4) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "counterclockwise") {
				curBlock->rotateCCW();
				if (curBlock->levelMade == 3 || curBlock->levelMade == 4) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				if (fp) {
					player1.printBoard();
				} else {
					player2.printBoard();
				}
			} else if (cmd == "drop") {
				int c_rows = player1.checkRows();
				curBlock->drop();
				curBlock->placeBlock();
				if (fp) {
					c_rows = player1.checkRows();
					if (c_rows > 0) {
						level_fp->counter = 0;
					} 	
					if (c_rows > 1) {
						cout << "Choose your special action (blind, heavy, force)" << endl;
						cin >> cmd;
						if (cmd == "blind") {
							player2.blind = true;
						} else if (cmd == "heavy") {
							player2.heavy = true;
						} else {
							player2.force = true;
							cin >> player2.forced;
						}
					}
					player1.printBoard();
				} else {
					c_rows = player2.checkRows();
					if (c_rows > 0) {
						level_sp->counter = 0;
					} 
					if (c_rows > 1) {
						cout << "Choose your special action (blind, heavy, force)" << endl;
						cin >> cmd;
						if (cmd == "blind") {
							player1.blind = true;
						} else if (cmd == "heavy") {
							player1.heavy = true;
						} else {
							player1.force = true;
							cin >> player1.forced;
						}
					}
					player2.printBoard();
				}
				//fp = !fp;
				break;
			} else if (cmd == "levelup") {
				if (fp) {
					if (player1.level == 4) {
						continue;
					} else {
						player1.level = player1.level + 1;
						cout << player1.level << endl;
					}

					Level *temp = level_fp;
					delete temp;
					if (player1.level == 1) {
						level_fp = new Level1;
					} else if (player1.level == 2) {
						level_fp = new Level2;
					} else {
						level_fp = new Level3;
					}

				} else {
					if (player2.level == 4) {
						continue;
					} else {
						player2.level = player2.level + 1;
						cout << player2.level << endl;
					}

					Level *temp = level_sp;
					delete temp;
					if (player2.level == 1) {
						level_sp = new Level1;
					} else if (player2.level == 2) {
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
			} else if (cmd == "I") {
				curBlock->clearBlock();
				if (fp) {
					curBlock = make_unique<IBlock>(0, player1.level, player1);
				} else {
					curBlock = make_unique<IBlock>(0, player1.level, player2);
				}
				curBlock->placeBlock();
				player1.printBoard();
			}
		}
	}
}

