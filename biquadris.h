#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"
#include "blocks.h"
#include <string>

class Biquadris: public Board {
	public:
	int width, height;
	bool in_file = false;
	std::string seq_1, seq_2;
	Board player1;
	Board player2;

	Blocks *curBlock;

	public:
	Biquadris();
	void playGame();
};
#endif

