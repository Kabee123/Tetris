#include "blocks.h"
using namespace std;

// Coords ctor
Coords::Coords(int x, int y): x{x}, y{y} {}


Blocks::Block(char type, int turn, int levelMade, vector<Coords> v, Board &b):
	type{type}, turn{turn}, level{levelMade}, cList{v}, board{b} {}	

// I Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade, 
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{3, 3}},
		Board) {}

// J Block
Blocks::JBlock(int turn, int levelMade, Board &b):
	Block('J', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{0, 3}, Coords{1, 3}, Coords{2, 3}},
		Board) {}

// L Block
Blocks::LBlock(int turn, int levelMade, Board &b):
        Block('L', turn, levelMade,
                vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{2, 2}},
                Board) {}

// O Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('O', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{0, 3}, Coords{1, 3}},
		Board) {}

// S Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('S', turn, levelMade,
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{1, 2}, Coords{2, 2}},
		Board) {}

// Z Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('Z', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 3}},
		Board) {}


// T Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{2, 2}, Coords{1, 3}},
		Board) {}


