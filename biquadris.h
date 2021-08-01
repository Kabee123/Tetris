#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"

class Biquadris: public Board {
	int wdith, height;
	Board player1;
	Board player2;

	public:
	Biquadris{};
	void playGame();
};
#endif

