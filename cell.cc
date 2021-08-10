#include "cell.h"
#include <iostream>

Cell::Cell(): type{'E'}, turn{-1}, levelMade{-1} {}

Cell::~Cell() {}

void Cell::setCell(char type, int turn, int level) {
	this->type = type;
	this->turn = turn;
	levelMade = level;
}

void Cell::resetCell() {
	type = 'E';
	turn = -1;
	levelMade = -1;
}

char Cell::getType() {
	return type;
}

int Cell::getTurn() {
	return turn;
}

int Cell::getLevel() {
	return levelMade;
}
