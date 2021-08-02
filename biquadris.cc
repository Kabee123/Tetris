#include "biquadris.h"
#include <string>
#include <stringstream>
#include <iostream>
#include <fstream>
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
	string c_seq;

	if (in_file) {
		std::ifsteam seq(c_seq);
		char bType;
		infile.get(bType)
	} else {

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
				



