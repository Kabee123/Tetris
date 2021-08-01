#include "cell.h"

Cell::Cell() {}

Cell::~Cell() {}

void Cell::setCell(char type, int turn, int level) {
	this->type = type;
	this->turn = turn;
	levelMade = level;
}

void Cell::resetCell() {
	char type = 'E';
	int turn = -1;
	int levelMade = -1;
}

