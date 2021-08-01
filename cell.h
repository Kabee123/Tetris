#ifndef _CELL_H_
#define _CELL_H_

class Cell {
	char type;
	int turn;
	int levelMade;
	//int x, y;
	public:
	setCell(char type, int turn, int level);
	resetCell();
}

#endif

