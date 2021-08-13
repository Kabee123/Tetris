#include "biquadris.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

Biquadris::Biquadris(bool display, int seed, string s1, string s2, int lvl) 
	: hiScore{0}, display{display}, seed{seed}, seq_1{s1}, seq_2{s2}, startlvl{lvl} {
		player1.init(lvl, seq_1);
		player2.init(lvl, seq_2);
		boards.emplace_back(&player1);
		boards.emplace_back(&player2);
		if (display) {	
		w.displayInit(startlvl);
		}
	}

void Biquadris::playGame() {
	istream *infile = &cin; //default value
	infile->exceptions( ios_base::failbit );
	bool fp = true; //fp = 1 and !fp = 0
	string cmd;
	char bType;

	char blk;
	
	int turn = -1;
	while (true) {
			
		try {
			if (infile->eof()) break;
		} catch (ios::failure &) {
			break;
		}

		if (fp) ++turn;	

		if (boards[!fp]->levelGen->counter > 0 && 
			boards[!fp]->levelGen->counter % 5 == 0) {
			boards[!fp]->bomb();
		}		
		if (boards[!fp]->getForce()) {
			bType = boards[!fp]->getForcedB();
			boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());
			boards[!fp]->setForce(false);
		} else {
			if (boards[!fp]->getNextB() == 'X') {
				bType = boards[!fp]->levelGen->makeBlock();
				boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());
				boards[fp]->setNextB(boards[fp]->levelGen->makeBlock());
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

		if (boards[fp]->getNextB() == 'I') {
			nextBlock = make_unique<IBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'J') {
            nextBlock = make_unique<JBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'L') {
            nextBlock = make_unique<LBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'O') {
            nextBlock = make_unique<OBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'Z') {
            nextBlock = make_unique<ZBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'S') {
            nextBlock = make_unique<SBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		} else if (boards[fp]->getNextB() == 'T') {
            nextBlock = make_unique<TBlock>(turn, boards[fp]->boardLevel(), boards[fp]);
		}

		nextBlock->placeBlock();
		curBlock->placeBlock();

		/*if (!nextBlock->placeBlock()) { 
		  cout << "PLAYER " << !fp << " CANNOT PLACE BLOCK" << endl; // IDK
		  break;
		}*/

		cout << boards;	
		if (display) { 
			w.updateNext(!fp, boards[!fp]->getNextB());
			w.updateNext(fp, boards[fp]->getNextB());
			w.updateDisplay(!fp, boards[!fp]);
			w.updateDisplay(fp, boards[fp]);
		}

		while (true) {

			try {
				*infile >> cmd;
				if (infile->eof()) break;
			} catch (ios::failure &) {
				break;
			}

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
			if (cmd == "lef" || cmd == "left" || 
					cmd == "ri" || cmd == "rig" || cmd == "righ" || cmd == "right") {
				if (display) w.removeBlock(!fp, curBlock->cList);

				if (cmd == "lef" || cmd == "left") {
					for (int i = 0; i < multPre; ++i) {
						if (!curBlock->move(-1, 0)) break;
					}
				} else {
					for (int i = 0; i < multPre; ++i) {
						if (!curBlock->move(1, 0)) break;
					}
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				if (fp && player1.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						player1.setHeavy(false);
						curBlock->placeBlock();
						fp = !fp;
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player1.setHeavy(false);
						curBlock->placeBlock();
						fp = !fp;
						break;
					}
				} else if (!fp && player2.getHeavy()) {
					if (!curBlock->move(0, 1)) {
						player2.setHeavy(false);
						curBlock->placeBlock();
						fp = !fp;
						break;
					}
					if (!curBlock->move(0,1)) {
						curBlock->placeBlock();
						player2.setHeavy(false);
						curBlock->placeBlock();
						fp = !fp;
						break;
					}
				}
				curBlock->placeBlock();
				cout << boards;
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "do" || cmd == "dow" || cmd == "down") {
				if (display) w.removeBlock(!fp, curBlock->cList);
				for (int i = 0; i < multPre; ++i) {
					if (!curBlock->move(0, 1)) break;
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "cl" || cmd == "clo" || cmd == "cloc" ||  
					cmd == "clock" || cmd == "clockw" || cmd == "clockwi" || 
					cmd == "clockwis" || cmd == "clockwise") {
				if (display) w.removeBlock(!fp, curBlock->cList);
				for (int i = 0; i < multPre; ++i) {
					if (!curBlock->rotateCW()) break;
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "co" || cmd == "cou" || cmd == "coun" || cmd == "count" || 
					cmd == "counte" || cmd == "counter" || cmd == "counterc" || cmd == "countercl" ||
					cmd == "counterclo" || cmd == "countercloc" || cmd == "counterclock" || cmd == "counterclockw" || 
					cmd == "counterclockwi" || cmd == "counterclockwis" || cmd == "counterclockwise") {
				if (display) w.removeBlock(!fp, curBlock->cList);
				for (int i = 0; i < multPre; ++i) {
					if(!curBlock->rotateCCW()) break;
				}
				if (curBlock->blockLevel() >= 3) {
					curBlock->move(0, 1);
				}
				curBlock->placeBlock();
				cout << boards;
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "dr" || cmd == "dro" || cmd == "drop") {
				if (display) w.removeBlock(!fp, curBlock->cList);
				int c_rows = 0;
				for (int i = 0; i < multPre; ++i) {
					curBlock->drop();
					curBlock->placeBlock();
					c_rows = boards[!fp]->checkRows();

					if (c_rows > 0) {
						if (display) { 
							w.removeRow(!fp, c_rows, boards[!fp]);
							w.updateDisplay(!fp, boards[!fp]);
						}
						boards[!fp]->setScore(pow(boards[!fp]->boardLevel() + c_rows, 2));
						if (display) w.updateScore(!fp, boards[!fp]->getScore());
						if (boards[!fp]->getScore() > hiScore) {
							hiScore = boards[!fp]->getScore();
							w.updateHiScore(hiScore);
						}
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
						if (display) w.showSpecial();
						*infile >> cmd;
						if (cmd == "blind") {
							boards[fp]->setBlind(true);
						} else if (cmd == "heavy") {
							boards[fp]->setHeavy(true);
						} else {
							boards[fp]->setForce(true);
							*infile >> blk;
							boards[fp]->setForcedB(blk);
							nextBlock->clearBlock();
						}
						if (display) w.clearSpecial();
					}

					if (multPre > 1) {
						bType = boards[!fp]->getNextB();
						boards[!fp]->setNextB(boards[!fp]->levelGen->makeBlock());

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
					}
				}
				if (boards[!fp]->getBlind()) {
					boards[!fp]->setBlind(false);
					if (display) w.removeBlind(!fp, boards[!fp]);
				} else {
					 w.updateDisplay(!fp, boards[!fp]);
				}
				fp = !fp;
				break;
			} else if (cmd == "levelu" || cmd == "levelup" || cmd == "leveld" || 
					cmd == "leveldo" || cmd == "leveldow" || cmd == "leveldown") {
				if (cmd == "levelu" || cmd == "levelup") {
					if (boards[!fp]->boardLevel() == 4) {
						continue;
					} else {
						for (int i = 0; i < multPre; ++i) {
							if (boards[!fp]->boardLevel() == 4) continue;
							boards[!fp]->setBoardLevel(boards[!fp]->boardLevel() + 1);
						}
					}
				} else {
					if (boards[!fp]->boardLevel() == 0) {
						continue;
					} else {
						for (int i = 0; i < multPre; ++i) {
							if (boards[!fp]->boardLevel() == 0) continue;
							boards[!fp]->setBoardLevel(boards[!fp]->boardLevel() - 1);
							
						}
					}
				}
				if (display) w.updateLevel(!fp, boards[!fp]->boardLevel());
				Level *temp = boards[!fp]->levelGen;
				delete temp;
				if (boards[!fp]->boardLevel() == 0) {
					if (fp) {
						boards[0]->levelGen = new Level0(seq_1);
					} else {
						boards[1]->levelGen = new Level0(seq_2);
					}
				} else if (boards[!fp]->boardLevel() == 1) {
					boards[!fp]->levelGen = new Level1;
				} else if (boards[!fp]->boardLevel() == 2) {
					boards[!fp]->levelGen = new Level2;
				} else if (boards[!fp]->boardLevel() == 3) {
					boards[!fp]->levelGen = new Level3;
				} else if (boards[!fp]->boardLevel() == 4) {
					boards[!fp]->levelGen = new Level4;
				}
				cout << boards;
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "ra" || cmd == "ran" || cmd == "rand" || 
					cmd == "rando" || cmd == "random") {
				boards[!fp]->levelGen->in_file = false;
			} else if (cmd == "n" || cmd == "no" || cmd == "nor" || 
					cmd == "nora" || cmd == "noran" || cmd == "norand" ||
					cmd == "norando" || cmd == "norandom") {
				cin >> boards[!fp]->levelGen->seq_file;
				boards[!fp]->levelGen->in_file = true;
			} else if (cmd == "se" || cmd == "seq" || cmd == "sequ" || cmd == "seque" ||
					cmd == "sequen" || cmd == "sequenc" || cmd == "sequence") {
				*infile >> cmd;
				infile = new ifstream(cmd);
				infile->exceptions(ios_base::eofbit | ios_base::failbit );
			} else if (cmd == "I" || cmd == "J" || cmd == "L" || cmd == "O" ||
					cmd == "S" || cmd == "Z" || cmd == "T") {
				if (display) w.removeBlock(!fp, curBlock->cList);
				int shiftx;
				int shifty;
				shiftx = curBlock->getBotL().x;
				shifty = curBlock->getBotL().y - 3;

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
				if (display) w.updateDisplay(!fp, boards[!fp]);
			} else if (cmd == "re" || cmd == "res" || cmd == "rest" || 
					cmd == "resta" || cmd == "restar" || cmd == "restart") {
				restartGame();
				cout << boards;
				if (display) w.resetDisplay();
				break;
			}	
		}
	}
	Level *temp1 = boards[0]->levelGen;
	delete temp1;
	Level *temp2 = boards[1]->levelGen;
	delete temp2;
	if ( infile != &cin ) delete infile;
}

void Biquadris::restartGame() {
	boards[0]->reset(seq_1);
	boards[1]->reset(seq_2);
	boards[0]->levelGen->counter = -1;
	boards[1]->levelGen->counter = -1;
}
