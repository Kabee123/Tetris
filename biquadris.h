#ifndef BIQUADRIS_H_
#define BIQUADRIS_H_
#include <iostream>
#include "board.h"
#include <string>

class Biquadris: public Board {
	public:
	int width, height;
	bool in_file = false;
	std::string seq_1, seq_2;
	Board player1;
	Board player2;

<<<<<<< HEAD
	public:
=======
>>>>>>> f67044d26b0542b2e44494004611cf09eef16778
	Biquadris();
	void playGame();
};
#endif

