#include "blocks.h"
using namespace std;

<<<<<<< HEAD
Blocks::Block(char type, int turn, int levelMade, vector<Coords> v, Board &b):
	type{type}, turn{turn}, level{levelMade}, cList{v}, Board{b} {}	
=======
// Coords ctor
Coords::Coords(int x, int y): x{x}, y{y} {}


Blocks::Block(char type, int turn, int levelMade, vector<Coords> v, Board &b):
	type{type}, turn{turn}, level{levelMade}, cList{v}, board{b} {}	
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// I Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade, 
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{3, 3}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// J Block
Blocks::JBlock(int turn, int levelMade, Board &b):
	Block('J', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{0, 3}, Coords{1, 3}, Coords{2, 3}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// L Block
Blocks::LBlock(int turn, int levelMade, Board &b):
        Block('L', turn, levelMade,
                vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{2, 2}},
<<<<<<< HEAD
                b) {}
=======
                Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// O Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('O', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{0, 3}, Coords{1, 3}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// S Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('S', turn, levelMade,
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{1, 2}, Coords{2, 2}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

// Z Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('Z', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 3}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}
>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca


// T Block
Blocks::IBlock(int turn, int levelMade, Board &b):
	Block('I', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{2, 2}, Coords{1, 3}},
<<<<<<< HEAD
		b) {}
=======
		Board) {}

>>>>>>> 6b926274e52f5921baf108c49ea95960b7dd36ca

