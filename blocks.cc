#include "blocks.h"
using namespace std;

Blocks::Block(char type, int turn, int levelMade, vector<Coords> v, Board &b):
	type{type}, turn{turn}, level{levelMade}, cList{v}, Board{b} {}	

// I Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade, 
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{3, 3}},
		b) {}

// J Block
Blocks::JBlock(int turn, int levelMade, Board &b):
	Block('J', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{0, 3}, Coords{1, 3}, Coords{2, 3}},
		b) {}

// L Block
Blocks::LBlock(int turn, int levelMade, Board &b):
        Block('L', turn, levelMade,
                vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{2, 2}},
                b) {}

// O Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('O', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{0, 3}, Coords{1, 3}},
		b) {}

// S Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('S', turn, levelMade,
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{1, 2}, Coords{2, 2}},
		b) {}

// Z Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('Z', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 3}},
		b) {}


// T Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{2, 2}, Coords{1, 3}},
		b) {}

