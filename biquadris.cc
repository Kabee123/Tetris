#include "biquadris.h"
#include <string>
#include <stringstream>
#include <iostream>
#include <fstream>
#include <levels.h>
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() : width{w}, height{h + reserve} {
	player1.init();
	player2.init();
}

void Biquadris::playGame() {
	string cmd;
	stringstream ss;
	char bType;
	bool first_p = true;

	if (in_file && first_p) {
		std::ifsteam seq(seq_1);
		infile.get(bType)
	} else if (in_file && !first_p) {
		std::ifsteam seq2(seq_1);
		infile.get(bType);
	}



	while (ss << cin && ss >> cmd) {
		switch (cmd) {
			case "left":

				break;
			case "right":

				break;
			case "down":

				break;
			case "I":

				break;
			case "J":

                                break;
			case "L":

				break;
			case "O":

				break;
			case "S":
			       
				break;
			case "Z":
			       
				break;
			case "T":
			       
				break;
		}
	}
}
				



