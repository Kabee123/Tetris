#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"
#include "blocks.h"
#include <string>
#include <memory>
#include "level.h"

class Biquadris: public Board {
	public:
	int level;
	int width, height;
	bool in_file = false;
	std::string seq_1, seq_2;
	Board player1;
	Board player2;

	std::unique_ptr<Blocks> curBlock;
	std::unique_ptr<Blocks> nexBlock;

	public:
	Biquadris();
	void playGame();
};
#endif

