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

void Board::reset() {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height + reserve; ++j) {
			theBoard[i][j].resetCell();
		}
	}
}

std::ostream &operator<<(std::ostream &out, vector<Board> boards) {
	int width = boards[0].width;
	int height = boards[0].height;
	int reserve = boards[0].reserve;
	for (int i = 0; i < height + reserve; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < width; ++k) {
				if (boards[j].blind && (i > 4 && i < 15) && (k > 2 && k < 10)) {
					out << '?';
				} else if (boards[j].theBoard[k][i].type == 'E') {
					if (i < 3) {
						out << '-';
					} else {
						out << '.';
					}
				} else {
					cout << "HERE";
					out << boards[j].theBoard[k][i].type;
				}
			}
			out << "     ";
		}
		out << endl;
	}
	return out;
}


void Board::printBoard() {
	for (int i = 0; i < height + reserve; ++i) {
		for (int j = 0; j < width; ++j) {
			if (blind && (i > 4 && i < 15)) {
				cout << '?';
			} else if (blind && (j > 1 && j < 9) && i > 2) {
				cout << '?';
			} else if (theBoard[j][i].type == 'E') {
				if (i < 3) {
					cout << '-';
				} else {
					cout << '.';
				}
			} else {
				cout << theBoard[j][i].type;
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
			if (theBoard[j][i].type != 'E' && theBoard[j][i].type != 'B') {
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

	for (int i = 0; i < r_fill.size(); ++i) {
		for (int j = r_fill[i]; j > reserve; --j) {
			for (int k = 0; k < width; ++k) {
				theBoard[k][j].type = theBoard[k][j-1].type;
				theBoard[k][j-1].resetCell();
			}
		}
	}

	return n_row;
}

void Board::bomb() {
	int mid = 5;
	if (theBoard[mid][reserve].type != 'E') {
		return;
	}

	for (int i = reserve; i < height + reserve - 1; ++i) {
		if (theBoard[mid][i + 1].type == 'E' && i == height + reserve - 2) {
			theBoard[mid][i + 1].setCell('*', 10, 4);
			return;
		} else if (theBoard[mid][i + 1].type == 'E') {
			continue;
		} else {
			theBoard[mid][i].setCell('*', 10, 4);
			return;
		}
	}
}



