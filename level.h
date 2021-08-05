#ifndef LEVEL_H_
#define LEVEL_H_
#include "board.h"

class Level {
	public:
		virtual char makeBlock()  = 0;
};

class Level0 : public Level {
        std::string file_name;
        int c_idx = 0;
        public:
        Level0(std::string file_name);
	virtual char makeBlock() override;
};

class Level1 : public Level {
        char makeBlock()  override;
};

class Level2 : public Level {
        char makeBlock()  override;
};

class Level3 : public Level {
        char makeBlock()  override;
};

class Level4 : public Level {
        char makeBlock()  override;
};

#endif

