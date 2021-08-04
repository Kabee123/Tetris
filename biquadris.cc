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

//for testing
	int i = 0;
	while (i < 2) {
		if (first_p) {
			getline(*infileP1, cmd);
			player1.printBoard();
		} else {
			getline(*infileP2, cmd);
			player2.printBoard();
		}
		
		
		if (cmd == "left") {


		} else if (cmd == "right") {


		} else if (cmd == "down") {


		} else if (cmd == "drop") {


		} else if (cmd == "I" or cmd == "J" or cmd == "L" or 
			   cmd == "O" or cmd == "S" or cmd == "Z" or cmd == "T") {
			player1.curBlock = cmd[0];

		}
		//first_p = !first_p;
		++i;
	}

	if (in_file) {
		delete infileP1;
		delete infileP2;
	}
}
				



