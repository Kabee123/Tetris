#include "biquadris.h"
#include <string>
#include <stringstream>
using namespace std;

const int w = 11;
const int h = 15;
const int reserve = 3;

Biquadris::Biquadris() : width{w}, height{h + reserve} {
	player1.init(width, height);
	player2.init(width, height);
}

void Biquadris::playGame() {
	string cmd;
	stringstream ss;
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
				



