#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"
#include "blocks.h"
#include <string>
#include <memory>
#include "level.h"
#include <vector>

class Biquadris: public Board {
	int level;
	int width, height;
	
	int hiScore;
	int score1;
	int score2;

	Board player1;
	Board player2;
	vector<Board*> boards;

	std::unique_ptr<Blocks> curBlock;
	std::unique_ptr<Blocks> nexBlock;

	public:
	bool in_file = false;
	std::string seq_1, seq_2;
	
	Biquadris();
	void playGame();
	void restartGame();
};
#endif

