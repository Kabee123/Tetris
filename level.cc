#include "level.h"
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

//display both block!!

Level0::Level0(std::string file_name) : file_name{file_name} {}

char Level0::makeBlock()  {
	char fType;
	char check_eof;
	char type;
	fstream seq(file_name);
	for (int i = 0; i <= c_idx; ++i) {
		if (i == 0) {
			seq.get(fType);
		} else {
			seq.get(type);
		}
		if (c_idx == 0) {
			++c_idx;
			return fType;
		}
		if (type == ' ') {
			seq.get(type);
		}
		seq.get(check_eof);
		if (seq.eof()) {
			c_idx = 1;
			return fType;
		}
	}
	++c_idx;
	return type;
}

char Level1::makeBlock()  {
	int num_prob = 12;
	int rand_c = rand() % num_prob;

	if (rand_c == 0) {
		return 'S';
	} else if (rand_c == 1) {
		return 'Z';
	} else if (rand_c <= 3) {
		return 'I';
	} else if (rand_c <= 5) {
		return 'J';
	} else if (rand_c <= 7) {
		return 'L';
	} else if (rand_c <= 9) {
		return 'O';
	} else if (rand_c <= 11) {
		return 'T';
	}
}


char Level2::makeBlock()  {
	int num_prob = 7;
	int rand_c = rand() % num_prob;

	if (rand_c == 0) {
		return 'S';
	} else if (rand_c == 1) {
		return 'Z';
	} else if (rand_c == 2) {
		return 'I';
	} else if (rand_c == 3) {
		return 'J';
	} else if (rand_c == 4) {
		return 'L';
	} else if (rand_c == 5) {
		return 'O';
	} else if (rand_c == 6) {
		return 'T';
	}
}

char Level3::makeBlock()  {
	if (in_file) {
		char fType;
		char check_eof;
		char type;
		fstream seq(seq_file);
		for (int i = 0; i <= c_idx; ++i) {
			if (i == 0) {
				seq.get(fType);
			} else {
				seq.get(type);
			}
			if (c_idx == 0) {
				++c_idx;
				return fType;
			}
			if (type == ' ') {
				seq.get(type);
			}
			seq.get(check_eof);
			if (seq.eof()) {
				c_idx = 1;
				return fType;
			}
		}
		++c_idx;
		return type;

	}
	c_idx = 0;
	int num_prob = 9;
	int rand_c = rand() % num_prob;

	if (rand_c <= 1) {
		return 'S';
	} else if (rand_c <= 3) {
		return 'Z';
	} else if (rand_c == 4) {
		return 'I';
	} else if (rand_c == 5) {
		return 'J';
	} else if (rand_c == 6) {
		return 'L';
	} else if (rand_c == 7) {
		return 'O';
	} else if (rand_c == 8) {
		return 'T';
	}
}

char Level4::makeBlock()  {
	if (in_file) {
		char fType;
		char check_eof;
		char type;
		fstream seq(seq_file);
		for (int i = 0; i <= c_idx; ++i) {
			if (i == 0) {
				seq.get(fType);
			} else {
				seq.get(type);
			}
			if (c_idx == 0) {
				++c_idx;
				return fType;
			}
			if (type == ' ') {
				seq.get(type);
			}
			seq.get(check_eof);
			if (seq.eof()) {
				c_idx = 1;
				return fType;
			}
		}
		++c_idx;
		return type;

	}
	c_idx = 0;
	int num_prob = 9;
	int rand_c = rand() % num_prob;

	if (rand_c <= 1) {
		return 'S';
	} else if (rand_c <= 3) {
		return 'Z';
	} else if (rand_c == 4) {
		return 'I';
	} else if (rand_c == 5) {
		return 'J';
	} else if (rand_c == 6) {
		return 'L';
	} else if (rand_c == 7) {
		return 'O';
	} else if (rand_c == 8) {
		return 'T';
	}
}



