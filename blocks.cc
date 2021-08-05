#include "blocks.h"
#include <cmath>
#include <iostream>
using namespace std;

// Coords ctor
Coords::Coords(int x, int y): x{x}, y{y} {}


Blocks::Blocks(char type, int turn, int levelMade, vector<Coords> v, Board &b):
	type{type}, turn{turn}, levelMade{levelMade}, cList{v}, board{b} {}	

// I Block
IBlock::IBlock(int turn, int levelMade, Board &b):
	Blocks('I', turn, levelMade, 
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{3, 3}},
		b) {}

// J Block
JBlock::JBlock(int turn, int levelMade, Board &b):
	Blocks('J', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{0, 3}, Coords{1, 3}, Coords{2, 3}},
		b) {}

// L Block
LBlock::LBlock(int turn, int levelMade, Board &b):
        Blocks('L', turn, levelMade,
                vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{2, 3}, Coords{2, 2}},
                b) {}

// O Block
OBlock::OBlock(int turn, int levelMade, Board &b):
	Blocks('O', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{0, 3}, Coords{1, 3}},
		b) {}

// S Block
SBlock::SBlock(int turn, int levelMade, Board &b):
	Blocks('S', turn, levelMade,
		vector<Coords>{Coords{0, 3}, Coords{1, 3}, Coords{1, 2}, Coords{2, 2}},
		b) {}

// Z Block
ZBlock::ZBlock(int turn, int levelMade, Board &b):
	Blocks('Z', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{1, 3}, Coords{2, 3}},
		b) {}


// T Block
TBlock::TBlock(int turn, int levelMade, Board &b):
	Blocks('I', turn, levelMade,
		vector<Coords>{Coords{0, 2}, Coords{1, 2}, Coords{2, 2}, Coords{1, 3}},
		b) {}

void Blocks::placeBlock() {
	for (int i = 0; i < cList.size(); ++i) {
		int x = cList[i].x;
		int y = cList[i].y;
		board.theBoard[x][y].setCell(type, turn, levelMade);
	}
}	

bool Blocks::move(int x, int y) {
	vector<Coords> tList;

	for (int i = 0; i < cList.size(); ++i) {
		cout << "start x: " << cList[i].x;
		cout << " start y: " << cList[i].y << endl;
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = tList[i].x + x;
		tList[i].y = tList[i].y + y;

		cout << "new x: " << tList[i].x;
		cout << " new y: " << tList[i].y << endl;


		if (board.theBoard[tList[i].x][tList[i].y].type != 'E') {
			return false;
		} else if (tList[i].x > (board.width - 1) || tList[i].x < 0) {
			return false;
		} else if (tList[i].y > (board.reserve + board.height - 1)) {
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
	cout << "DROP:" << endl;

        for (int i = 0; i < cList.size(); ++i) {
		Coords cds(cList[i].x, cList[i].y);
                tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
        }

	cout << "copied" << endl;
        while(true) {
                for (int i = 0; i < tList.size(); ++i) {
                        if (tList[i].y + 1 > (board.reserve + board.height - 1)) {
                                return;
                        } else if (board.theBoard[tList[i].x][tList[i].y + 1].type != 'E') {
                                return;
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
	vector<Coords> tList; 

	for (int i = 0; i < cList.size(); ++i) {
		cout << "start x: " << cList[i].x;
		                cout << " start y: " << cList[i].y << endl;
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}
	
	int startx = tList[0].x;
	int starty = tList[0].y;
	int width = abs(tList[0].x - tList[3].x) + 1;
	int height = abs(tList[0].y - tList[3].x) + 1;
	
	cout << "W: " << width << " H: " << height << endl;

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = cList[i].x * 0 + cList[i].y * -1 + width + startx;
		tList[i].y = cList[i].x * 1 + cList[i].y * 0 + height - starty;


		cout << "new x: " << tList[i].x;
		cout << " new y: " << tList[i].y << endl;
	}

	for (int i = 0; i < cList.size(); ++i) {
		cList[i].x = tList[i].x;
		cList[i].y = tList[i].y;
	}

	return true;

}

bool Blocks::rotateCCW() {
	vector<Coords> tList;
cout <<"CCW"<<endl;	
	for (int i = 0; i < cList.size(); ++i) {
		cout << "start x: " << cList[i].x;
		cout << " start y: " << cList[i].y << endl;
		Coords cds(cList[i].x, cList[i].y);
		tList.emplace_back(cds);
		board.theBoard[cList[i].x][cList[i].y].resetCell();
	}

	int width = abs(tList[0].x - tList[3].x);
	int height = abs(tList[0].y - tList[3].x);

	cout << "W: " << width << " H: " << height << endl;

	for (int i = 0; i < tList.size(); ++i) {
		tList[i].x = cList[i].x * 0 + cList[i].y * -1 + width; 
		tList[i].y = cList[i].x * 1 + cList[i].y * 0;
	
		cout << "new x: " << tList[i].x;
		cout << " new y: " << tList[i].y << endl;
	}

	for (int i = 0; i < cList.size(); ++i) {
                cList[i].x = tList[i].x;
		cList[i].y = tList[i].y;
	}

        return true;

}

