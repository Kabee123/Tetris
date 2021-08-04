#include "board.h"
#include <iostream>
#include <utility>
using namespace std;

//Board::Board() {}

//Board::~Board() {};

void Board::init() {

	//make board
	for (int i = 0; i < width; ++i) {
		vector<Cell> v;
		for (int j = 0; j < height + reserve; ++j) {
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

int Board::checkRows() {
	int n_row = 0;
	vector<int> r_fill;
	for (int i = reserve; i < height + reserve; ++i) {
		int fill_b = 0;
		for (int j = 0; j < width; ++j) {
			if (theBoard[j][i].type != 'E') {
				++fill_b;
			}
		}
		if (fill_b == width) {
			r_fill.emplace_back(i);
			++n_row;
		}
	}

	for (int i = 0; i < r_fill.size(); ++i) {
		for (int j = 0; j < width; ++j) {
			theBoard[j][r_fill[i]].resetCell();
		}
	}

	return n_row;
}


