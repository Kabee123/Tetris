#include "board.h"
#include <iostream>
using namespace std;

Board::Board() {};

Board::~Board() {};

void Board::init(int width, int height) {
	this->width = width;
	this->height = height;

	//make board
	for (int i = 0; i < width, ++i) {
		vector<Cell> v;
		for (int j = 0; j < height; ++j) {
			Cell c;
			v.emplace_back(c);
		}
		theBoard.emplace_back(v);
	}
}

void Board::printBoard() {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++ j) {
			if (j < 3) {
				cout << '-';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}

