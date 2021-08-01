#include "level.h"
#include <rand>

using namespace std;

char Level1::makeBlock() {
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


char Level2::makeBlock() {
        int num_prob = 7;
        int rand_c = rand() % num_prob;

        if (rand_c == 0) {
                return 'S'
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

        return cptr;
}

char Level3::makeBlock() {
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

char Level4::makeBlock() {
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



