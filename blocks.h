#ifndef _BLOCKS_H_
#define _BLOCKS_H_
#include <vector>
#include "board.h"

class Coords {
	protected:
	int x, y;
};

class Blocks {
	char type;
	int turn;
	int levelMade;
	vector<Coords> cList; 
	Board &board;
	public:
	Blocks(char type, int turn, int levelMades, vector<Coords> v, Board &b);
	bool move(int x, int y);
	void drop();
	void rotateCW();
	void rotateCCW();
	void clearBlock();
};

class IBlock : public Blocks {
	public:
		IBlock(int turn, int levelMade, Board &b);
};


class JBlock : public Blocks {
	public:
		JBlock(int turn, int levelMade, Board &b);
};


class LBlock : public Blocks {
	public:
		LBlock(int turn, int levelMade, Board &b);
};


class OBlock : public Blocks {
	public:
		OBlock(int turn, int levelMade, Board &b);
};


class ZBlock : public Blocks {
	public:
		ZBlock(int turn, int levelMade, Board &b);
};


class SBlock : public Blocks {
	public:
		SBlock(int turn, int levelMade, Board &b);
};


class TBlock : public Blocks {
	public:
		TBlock(int turn, int levelMade, Board &b);
};

#endif

