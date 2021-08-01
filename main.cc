#include "biquadris.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 1) {
		cout << "Usage: " << argv[0] << endl;
		return 1;
	}
	biquadris g{};
	g.playGame;
}

