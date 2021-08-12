#ifndef _BLOCKS_H_
#define _BLOCKS_H_
#include "board.h"
#include "cell.h"
#include <vector>


class Coords {
	public:
	int x, y;
	Coords(int x, int y);
};

class Blocks {
	char type;
	int turn;
	int levelMade;
	int width;
	int height;
	Coords botLeft;
	
	Board *board;
	public:
	std::vector<Coords> cList; 
	Blocks(char type, int turn, int levelMades, int w, int h, Coords corner, std::vector<Coords> v, Board *b);
	bool placeBlock();
	bool move(int x, int y);
	void drop();
	bool rotateCW();
	bool rotateCCW();
	void clearBlock();

	Coords getBotL();

	char blockType();
	int blockTurn();
	int blockLevel();
};

class IBlock : public Blocks {
	public:
		IBlock(int turn, int levelMade, Board *b);
};


class JBlock : public Blocks {
	public:
		JBlock(int turn, int levelMade, Board *b);
};


class LBlock : public Blocks {
	public:
		LBlock(int turn, int levelMade, Board *b);
};


class OBlock : public Blocks {
	public:
		OBlock(int turn, int levelMade, Board *b);
};


class ZBlock : public Blocks {
	public:
		ZBlock(int turn, int levelMade, Board *b);
};


class SBlock : public Blocks {
	public:
		SBlock(int turn, int levelMade, Board *b);
};


class TBlock : public Blocks {
	public:
		TBlock(int turn, int levelMade, Board *b);
};


#endif

