#include "board.h"
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

int Board::boardLevel() {
	return level;
}

void Board::setBoardLevel(int l) {
	level = l;
}

int Board::boardW() {
	return width;
}

int Board::boardH() {
	return height + reserve;
}

char Board::getNextB() {
	return nextBlock;
}

void Board::setNextB(char blk) {
	nextBlock = blk;
}

int Board::getScore() {
	return score;
}

void Board::setScore(int s) {
	score += s;
}

bool Board::getBlind() {
	return blind;
}

void Board::setBlind(bool b) {
	blind = b;
}

bool Board::getHeavy() {
	return heavy;
}

void Board::setHeavy(bool b) {
	heavy = b;
}

bool Board::getForce() {
	return force;
}

void Board::setForce(bool b) {
	force = b;
}

char Board::getForcedB() {
	return forced;
}

void Board::setForcedB(char blk) {
	forced = blk;
}

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

std::ostream &operator<<(std::ostream &out, vector<Board*> boards) {
	int width = boards[0]->width;
	int height = boards[0]->height;
	int reserve = boards[0]->reserve;

	out << "PLAYER    1     PLAYER    2" << endl;
	out << "LEVEL: " << setw(4) << boards[0]->level << "     ";
	out << "LEVEL: " << setw(4) << boards[1]->level << endl;
	out << "SCORE: " << setw(4) << boards[0]->score << "     ";
	out << "SCORE: " << setw(4) << boards[1]->score << endl;

	for (int i = 0; i < height + reserve; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < width; ++k) {
				if (boards[j]->blind && (i > 4 && i < 15) && (k > 1 && k < 9)) {
					out << '?';
				} else if (boards[j]->theBoard[k][i].getType() == 'E') {
					if (i < 3) {
						out << '-';
					} else {
						out << '.';
					}
				} else {
					out << boards[j]->theBoard[k][i].getType();
				}
			}
			out << "     ";
		}
		out << endl;
	}
	out << "NEXT: " << setw(5) << boards[0]->nextBlock << "     ";
	out << "NEXT: " << setw(5) << boards[1]->nextBlock << endl;

	return out;
}

/*
void Board::printBoard() {
	for (int i = 0; i < height + reserve; ++i) {
		for (int j = 0; j < width; ++j) {
			if (blind && (i > 4 && i < 15)) {
				cout << '?';
			} else if (blind && (j > 1 && j < 9) && i > 2) {
				cout << '?';
			} else if (theBoard[j][i].getType() == 'E') {
				if (i < 3) {
					cout << '-';
				} else {
					cout << '.';
				}
			} else {
				cout << theBoard[j][i].getType();
			}
		}
		cout << endl;
	}
	cout << endl;
}
*/

int Board::checkRows() {
	int n_row = 0;
	vector<int> r_fill;
	for (int i = reserve; i < height + reserve; ++i) {
		int fill_b = 0;
		for (int j = 0; j < width; ++j) {
			if (theBoard[j][i].getType() != 'E' && theBoard[j][i].getType() != 'B') {
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
				theBoard[k][j].setCell(theBoard[k][j-1].getType(), 
					theBoard[k][j-1].getTurn(), theBoard[k][j-1].getLevel());
				theBoard[k][j-1].resetCell();
			}
		}
	}

	return n_row;
}

void Board::bomb() {
	int mid = 5;
	if (theBoard[mid][reserve].getType() != 'E') {
		return;
	}

	for (int i = reserve; i < height + reserve - 1; ++i) {
		if (theBoard[mid][i + 1].getType() == 'E' && i == height + reserve - 2) {
			theBoard[mid][i + 1].setCell('*', 10, 4);
			return;
		} else if (theBoard[mid][i + 1].getType() == 'E') {
			continue;
		} else {
			theBoard[mid][i].setCell('*', 10, 4);
			return;
		}
	}
}



