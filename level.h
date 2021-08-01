#ifndef LEVEL_H_
#define LEVEL_H_
#include "board.h"

class Level {
	public:
		virtual char makeBlock() const = 0;
};

class Level1 : public Level {
	virtual char makeBlock() override;
};

#endif

