#include "biquadris.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "level.h"
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() {
	player1.init();
	player2.init();
}

void Biquadris::playGame() {

	string cmd;
	
	istream *infileP1 = &cin; //default values
	istream *infileP2 = &cin;

	char bType;
	bool first_p = true;

	if (in_file && first_p) {
		infileP1 = new ifstream(seq_1);
		//seq.get(bType);
	} else if (in_file && !first_p) {
		infileP2 = new ifstream(seq_2);
		//seq2.get(bType);
	}

	cout << "PLAYING" << endl;
	player1.printBoard();

//for testing
	int i = 0;
	while (i < 5) {
		cout << "TYPE:" << curBlock->type << endl;
		if (first_p) {
			getline(*infileP1, cmd);
			cout << "After:";
		} else {
			getline(*infileP2, cmd);
		}	
		cout << cmd << endl;	
		if (cmd == "left") {
			curBlock->move(-1, 0);
			curBlock->placeBlock();
		} else if (cmd == "right") {
			curBlock->move(1, 0);
			curBlock->placeBlock();
	
		} else if (cmd == "down") {
			curBlock->move(0, -1);
			
		} else if (cmd == "clockwise") {


		} else if (cmd == "counterclockwise") {


		} else if (cmd == "drop") {


		} else if (cmd == "I") {
			IBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		} else if (cmd == "J") {
			JBlock temp{0, 0, player1};
 			curBlock = &temp;
			curBlock->placeBlock();
		} else if (cmd == "L") {
			LBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		} else if (cmd == "O") {
                        OBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		} else if (cmd == "Z") {
	                ZBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		} else if (cmd == "S") {
	                SBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		//	player1.printBoard();
		//	curBlock->move(1, 0);
		//	curBlock->placeBlock();
		} else if (cmd == "T") {
	                TBlock temp{0, 0, player1};
			curBlock = &temp;
			curBlock->placeBlock();
		}	       
		//first_p = !first_p;
		player1.printBoard();
		++i;
	}

	if (in_file) {
		delete infileP1;
		delete infileP2;
	}
}
				



