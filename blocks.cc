#include "blocks.h"
#include <cmath>
#include <iostream>
using namespace std;

// Coords ctor
Coords::Coords(int x, int y): x{x}, y{y} {}


Blocks::Blocks(char type, int turn, int levelMade, int w, int h, Coords corner, vector<Coords> v, Board &b):
	type{type}, turn{turn}, levelMade{levelMade}, width{w}, height{h}, botLeft{corner}, cList{v}, board{b} {}	

// I Block
IBlock::IBlock(int turn, int levelMade, Board &b):
	Blocks('I', turn, levelMade, 4, 1, Coords{0, 3}, 
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{3, 3}},
		b) {}

// J Block
JBlock::JBlock(int turn, int levelMade, Board &b):
	Blocks('J', turn, levelMade, 3, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 2}, Coords{0, 3}, Coords{1, 3}, Coords{2, 3}},
		b) {}

// L Block
LBlock::LBlock(int turn, int levelMade, Board &b):
	Blocks('L', turn, levelMade, 3, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{2, 2}},
		b) {}

// O Block
OBlock::OBlock(int turn, int levelMade, Board &b):
	Blocks('O', turn, levelMade, 2, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{0, 3}, Coords{1, 3}},
		b) {}

// S Block
SBlock::SBlock(int turn, int levelMade, Board &b):
	Blocks('S', turn, levelMade, 3, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{1, 2}, Coords{2, 2}},
		b) {}

// Z Block
ZBlock::ZBlock(int turn, int levelMade, Board &b):
	Blocks('Z', turn, levelMade, 3, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 3}},
		b) {}


// T Block
TBlock::TBlock(int turn, int levelMade, Board &b):
	Blocks('T', turn, levelMade, 3, 2, Coords{0, 3},
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 2}},
		b) {}

bool Blocks::placeBlock() {
	for (int i = 0; i < cList.size(); ++i) {
		int x = cList[i].x;
		int y = cList[i].y;
		if (board.theBoard[x][y].type != 'E') return false;
		board.theBoard[x][y].setCell(type, turn, levelMade);
	}
	return true;
}	





bool Blocks::move(int x, int y) {
	vector<Coords> tList;

	for (int i = 0; i < cList.size(); ++i) {
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = tList[i].x + x;
		tList[i].y = tList[i].y + y;

		if (tList[i].x > (board.width - 1) || tList[i].x < 0) {
			return false;
		} else if (tList[i].y > (board.reserve + board.height - 1)) {
			return false;
		} else if (board.theBoard[tList[i].x][tList[i].y].type != 'E') {
			return false;
		}
	}

	for (int i = 0; i < cList.size(); ++i) {
		cList[i].x = tList[i].x;
		cList[i].y = tList[i].y;
	}

	botLeft.x += x;
	botLeft.y += y;

	return true;
}

void Blocks::drop() {
	if (board.blind) {
		board.blind = false;
	} 
	if (board.heavy) {
		board.heavy = false;
	}

	while(this->move(0, 1)) {

	}
}

bool Blocks::rotateCW() {
	vector<Coords> tList; 

	for (int i = 0; i < cList.size(); ++i) {
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = cList[i].y *-1 + botLeft.x + botLeft.y;
		tList[i].y = cList[i].x - (botLeft.x + (width - 1) - botLeft.y);

		if (tList[i].x > (board.width - 1) || tList[i].x < 0) {
			return false;
		} else if (tList[i].y > (board.reserve + board.height - 1)) {
			return false;
		} else if (board.theBoard[tList[i].x][tList[i].y].type != 'E') {
			return false;
		}

	}
	 
	int oldWidth = width;
	width = height;
	height = oldWidth;

	for (int i = 0; i < cList.size(); ++i) {
		cList[i].x = tList[i].x;
		cList[i].y = tList[i].y;
	}

	return true;

}

bool Blocks::rotateCCW() {
	vector<Coords> tList;
	
	for (int i = 0; i < cList.size(); ++i) {
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = cList[i].y + (botLeft.x + (height - 1) - botLeft.y); 
		tList[i].y = cList[i].x * -1 + botLeft.x + botLeft.y;
		if (tList[i].x > (board.width - 1) || tList[i].x < 0) {
			return false;
		} else if (tList[i].y > (board.reserve + board.height - 1)) {
			return false;
		} else if (board.theBoard[tList[i].x][tList[i].y].type != 'E') {
			return false;
		}
	}

	int oldWidth = width;
	width = height;
	height = oldWidth;

	for (int i = 0; i < cList.size(); ++i) {
		cList[i].x = tList[i].x;
		cList[i].y = tList[i].y;
	}

	return true;

}

void Blocks::clearBlock() {
	for (int i = 0; i < cList.size(); ++i) {
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}
}

