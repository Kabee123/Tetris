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

Biquadris::Biquadris(bool tdOnly, int seed, string s1, string s2, int lvl) 
: hiScore{0}, textOnly{tdOnly}, seed{seed}, seq_1{s1}, seq_2{s2}, startlvl{lvl} {
	player1.init(lvl, seq_1);
	player2.init(lvl, seq_2);
	boards.emplace_back(&player1);
	boards.emplace_back(&player2);
}

void Biquadris::playGame() {
	istream *infile = &cin; //default value
	infile->exceptions( ios_base::failbit );
	//std::srand(std::time (NULL));
	bool fp = true; //fp = 1 and !fp = 0
	string cmd;
	char bType;

	int blk;

	int turn = -1;
	while (true) {
		//if (infile->eof()) break;
		try {
			infile->eof();
		} catch (ios::failure &) {
			cout << "WILLIAM" << endl;
			break;
			
		}
		/*if (cin.eof()) {
			break;
		}*/
		if (fp) ++turn;	
		//cout << "COUNTER: " << boards[!fp]->levelGen->counter << endl;
		if (boards[!fp]->levelGen->counter > 0 && 
			boards[!fp]->levelGen->counter % 5 == 0) {
				cout << "TRIGGERED" << endl;
				boards[!fp]->bomb();
		}		
		if (boards[!fp]->getForce()) {
			bType = boards[!fp]->getForcedB();
			boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());
			boards[!fp]->setForce(false);
		} else {
			if (boards[!fp]->getNextB() == 'X') {
				cout << "BEFORE" << endl;
				bType = boards[!fp]->levelGen->makeBlock();
				boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());
				cout << "AFTER" << endl;
			} else {
				bType = boards[!fp]->getNextB();
				boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());
			}
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

		if (!curBlock->placeBlock()) { 
			cout << "YOU LOST" << endl; // IDK
			break;
		}

		cout << boards;	

		while (true) {
			
			try {
				*infile >> cmd;
			} catch (ios::failure &) {
				break;
			}
			//while true w/ try catch inside

			//prefixing
			int multPre = 1;
			string prefix{""};
			for (int i = 0; i < cmd.size(); ++i) {
				if ('0' <= cmd[i] && cmd[i] <= '9') {
					prefix += cmd[i];
				} else {
					cmd = cmd.substr(i);
					break;
				}
			}
			if (prefix != "") {
				multPre = stoi(prefix);
			}

			if (cmd == "left" or cmd == "right") {
				if (cmd == "left") {
					for (int i = 0; i < multPre; ++i) {
						if (!curBlock->move(-1, 0)) break;
					}
				} else if (cmd == "right") {
					for (int i = 0; i < multPre; ++i) {
						if (!curBlock->move(1, 0)) break;
					}
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				if (fp && player1.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						player1.setHeavy(false);
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player1.setHeavy(false);
						break;
					}
				} else if (!fp && player2.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						player2.setHeavy(false);
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player2.setHeavy(false);
						break;
					}
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "down") {
				for (int i = 0; i < multPre; ++i) {
						if (!curBlock->move(0, 1)) break;
					}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "clockwise") {
				for (int i = 0; i < multPre; ++i) {
					if (!curBlock->rotateCW()) break;
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
			} else if (cmd == "counterclockwise") {
				for (int i = 0; i < multPre; ++i) {
					if(!curBlock->rotateCCW()) break;
				}
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

				if (c_rows > 0) {
					boards[!fp]->setScore(pow(boards[!fp]->boardLevel() + c_rows, 2));
					boards[!fp]->levelGen->counter = 0;
				} else {
					if (boards[!fp]->boardLevel() == 4) {
						if (boards[!fp]->levelGen->counter == -1) {
							boards[!fp]->levelGen->counter += 1;
						}
						boards[!fp]->levelGen->counter += 1;
					}
				}

				if (c_rows > 1) {
					cout << "Choose your special action (blind, heavy, force)" << endl;
						*infile >> cmd;
					if (cmd == "blind") {
						boards[fp]->setBlind(true);
					} else if (cmd == "heavy") {
						boards[fp]->setHeavy(true);
					} else {
						boards[fp]->setForce(true);
						*infile >> blk;
						boards[fp]->setForcedB(blk);
					}
				}
				cout << boards;
				fp = !fp;
				break;
			} else if (cmd == "levelup" || cmd == "leveldown") {
				if (cmd == "levelup") {
					if (boards[!fp]->boardLevel() == 4) {
						continue;
					} else {
						for (int i = 0; i < multPre; ++i) {
							if (boards[!fp]->boardLevel() == 4) break;
							boards[!fp]->setBoardLevel(boards[!fp]->boardLevel() + 1);
						}
					}
				} else {
					if (boards[!fp]->boardLevel() == 0) {
						continue;
					} else {
						for (int i = 0; i < multPre; ++i) {
							if (boards[!fp]->boardLevel() == 0) break;
							boards[!fp]->setBoardLevel(boards[!fp]->boardLevel() - 1);
						}
					}
				}
				Level *temp = boards[!fp]->levelGen;
				delete temp;
				if (boards[!fp]->boardLevel() == 1) {
					boards[!fp]->levelGen = new Level1;
				} else if (boards[!fp]->boardLevel() == 2) {
					boards[!fp]->levelGen = new Level2;
				} else if (boards[!fp]->boardLevel() == 3) {
					boards[!fp]->levelGen = new Level3;
				} else if (boards[!fp]->boardLevel() == 4) {
					boards[!fp]->levelGen = new Level4;
				}
				cout << boards;
			} else if (cmd == "random") {
				boards[!fp]->levelGen->in_file = false;
			} else if (cmd == "norandom") {
				if (fp) {
					boards[!fp]->levelGen->seq_file = seq_1;
				} else {
					boards[!fp]->levelGen->seq_file = seq_2;
				}
				boards[!fp]->levelGen->in_file = true;
			} else if (cmd == "sequence") {
				try {
					*infile >> cmd;
					infile = new ifstream(cmd);
					infile->exceptions( ios_base::failbit );
				} catch (ios::failure &) {
					cout << "KEFAN" << endl;
					break;
				}
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
				cout << boards;
				break;
			}	
		}
	}
	if ( infile != &cin ) delete infile;
}

void Biquadris::restartGame() {
	boards[0]->reset(seq_1);
	boards[1]->reset(seq_2);
	boards[0]->levelGen->counter = -1;
	boards[1]->levelGen->counter = -1;
}
