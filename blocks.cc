#include "blocks.h"
using namespace std;

// Coords ctor
Coords::Coords(int x, int y): x{x}, y{y} {}


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

bool Blocks::move(int x, int y) {
	vector<Coords> tList;

	for (int i = 0; i < cList.size(); ++i) {
		tList[i].x = cList[i].x;
		tList[i].y = cList[i].y;
	}

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = tList[i].x + x;
		tList[i].y = tList[i].y + y;

		if (board->theBoard[tList[i].x][tList[i].y]->cell.type != 'E') {
			return false;
		} else if (tlist[i].x > (board->width - 1) || tlist[i].x < 0) {
			return false;
		} else if (tlist[i].y > (board->reserve + board->height - 1)) {
			return false;
		}
	}

	for (int i = 0; i < cList.size(); ++i) {
                cList[i].x = tList[i].x;
                cList[i].y = tList[i].y;
        }

	return true;
}

void Blocks::drop() {
        vector<Coords> tList;

        for (int i = 0; i < cList.size(); ++i) {
                tList[i].x = cList[i].x;
                tList[i].y = cList[i].y;
        }

        while(true) {
                for (int i = 0; i < tList.size(); ++i) {
                        if (tList[i].y + 1 > (board->reserve + board->height - 1)) {
                                break;
                        } else if (board->theBoard[tList[i].x][tList[i].y + 1]->cell.type != 'E') {
                                break;
                        } else {
                                tList[i].y = tList[i].y + 1;
                        }
                }

                for (int i = 0; i < cList.size(); ++i) {
                        cList[i].x = tList[i].x;
                        cList[i].y = tList[i].y;
                }
        }
}


bool Blocks::rotateCW() {

}


bool Blocks::rotateCCW() {
	vector<Coords> tList; 

	for (int i = 0; i < cList.size(); ++i) {
		tList[i].x = cList[i].x;
		tList[i].y = cList[i].y;
	}

	int width = abs(tList[0].x - tList[3].x);
	int height = abs(tList[0].y - tList[3].x);

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = tList[i].x * 0 + tList[i].y * 1 - width;
		tList[i].y = tList[i].x * -1 + tList[i].y * 0 + 2 * height;
	}

}


