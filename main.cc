#include "biquadris.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {

	string text{"-text"};
	string seed{"-seed"};
	string sfile1{"-scriptfile1"};
	string sfile2{".scriptfile2"};
	string level{"-startlevel"};

	bool textOnly = false;
	int theSeed; //idk if correct default
	string s1{"sequence1.txt"};
	string s2{"sequence2.txt"};
	int theLevel = 0;

	for (int i = 1; i < argc; ++i) {
		string s{""};
		stringstream ss;
		s += argv[i];
		if (s.find(text) != string::npos) {
			textOnly = true;
		} else if (s.find(seed) != string::npos) {
			++i;
			s = "";
			s += argv[i];
			theSeed = stoi(s);
			std::srand(theSeed);
		} else if (s.find(sfile1) != string::npos) {
			++i;
			s1 = "";
			s1 += argv[i];
			//ss >> s1;
		} else if (s.find(sfile2) != string::npos) {
			++i;
			s2 = "";
			s2 += argv[i];
			//ss >> s2;
		} else if (s.find(level) != string::npos) {
			++i;
			s = "";
			s += argv[i];
			theLevel = stoi(s);
		}
	}

	/*if (argc > 1) {
		g.in_file = true;
		g.seq_1 = argv[1];
		g.seq_2 = argv[2];
	}*/

	Biquadris g{textOnly, theSeed, s1, s2, theLevel};
	g.playGame();
}

