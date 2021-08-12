#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"
#include "blocks.h"
#include <string>
#include <memory>
#include "level.h"
#include "window.h"
#include <vector>

class Biquadris: public Board {
	int hiScore;

	bool textOnly;
	int seed;
	std::string seq_1, seq_2;
	int startlvl;

	Board player1;
	Board player2;
	vector<Board*> boards;

	std::unique_ptr<Blocks> curBlock;
	//std::unique_ptr<Blocks> nexBlock1;

	//std::unique_ptr<Blocks> curBlock2;
	//std::unique_ptr<Blocks> nexBlock2;
	
	Xwindow w;
	public:
	//bool in_file = false;	
	Biquadris(bool tdOnly, int seed, std::string s1, std::string s2, int lvl);
	void playGame();
	void restartGame();
};
#endif

