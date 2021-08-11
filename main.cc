#include "biquadris.h"
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	Biquadris g{};

	string text{"-text"};
	string seed{"-seed"};
	string sfile1{"-scriptfile1"};
	string sfile2{".scriptfile2"};
	string level{"-startlevel"};

	for (int i = 1; i < argc; ++i) {
		string s;
		stringstream ss;
		ss << argv[i];
		ss >> s;
		if (s.find(text) != string::npos) {

		} else if (s.find(seed) != string::npos) {

		} else if (s.find(sfile1) != string::npos) {

		} else if (s.find(sfile2) != string::npos) {

		} else if (s.find(level) != string::npos) {

		}
	}

	/*if (argc > 1) {
		g.in_file = true;
		g.seq_1 = argv[1];
		g.seq_2 = argv[2];
	}*/

	g.playGame();
}

