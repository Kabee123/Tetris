#ifndef LEVEL_H_
#define LEVEL_H_
#include "board.h"

class Level {
	public:
		virtual char makeBlock() const = 0;
};

/*class Level_0 : public Level {
	virtual char makeBlock() override;
};*/

class Level1 : public Level {
        virtual char makeBlock() override;
};

class Level2 : public Level {
        virtual char makeBlock() override;
};

class Level3 : public Level {
        virtual char makeBlock() override;
};

class Level4 : public Level {
        virtual char makeBlock() override;
};


#endif

