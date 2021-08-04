#ifndef _CELL_H_
#define _CELL_H_

class Cell {
	public:
	char type;
	int turn;
	int levelMade;
	//int x, y;

	Cell();	
	~Cell();
	void setCell(char type, int turn, int level);
	void resetCell();
};

#endif

