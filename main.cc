#include "biquadris.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 1) {
		cout << "Usage: " << argv[0] << endl;
		return 1;
	}
	biquadris g{};

	if (argc > 1) {
		g.in_file = true;
		g.seq_1 = argv[1];
		g.seq_2 = argv[2];
	}

	g.playGame;
}

