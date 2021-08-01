#include "level.h"
#include <rand>

using namespace std;

char Level1::makeBlock() {
	char * cptr;
	int num_prob = 12;
	int rand_c = rand() % num_prob;

	if (rand_c == 0) {
		*cptr = 'S';
	} else if (rand_c == 1) {
		*cptr = 'Z';
	} else if (rand_c <= 3) {
		*cptr = 'I';
	} else if (rand_c <= 5) {
                *cptr = 'J';
        } else if (rand_c <= 7) {
                *cptr = 'L';
        } else if (rand_c <= 9) {
                *cptr = 'O';
	} else if (rand_c <= 11) {
                *cptr = 'T';
	}

	return cptr;
}


char Level2::makeBlock() {
        char * cptr;
        int num_prob = 7;
        int rand_c = rand() % num_prob;

        if (rand_c == 0) {
                *cptr = 'S';
        } else if (rand_c == 1) {
                *cptr = 'Z';
        } else if (rand_c == 2) {
                *cptr = 'I';
        } else if (rand_c == 3) {
                *cptr = 'J';
        } else if (rand_c == 4) {
                *cptr = 'L';
        } else if (rand_c == 5) {
                *cptr = 'O';
        } else if (rand_c == 6) {
                *cptr = 'T';
        }

        return cptr;
}

char Level3::makeBlock() {
        char * cptr;
        int num_prob = 9;
        int rand_c = rand() % num_prob;

        if (rand_c <= 1) {
                *cptr = 'S';
        } else if (rand_c <= 3) {
                *cptr = 'Z';
        } else if (rand_c == 4) {
                *cptr = 'I';
        } else if (rand_c == 5) {
                *cptr = 'J';
        } else if (rand_c == 6) {
                *cptr = 'L';
        } else if (rand_c == 7) {
                *cptr = 'O';
        } else if (rand_c == 8) {
                *cptr = 'T';
        }

        return cptr;
}

char Level4::makeBlock() {
        char * cptr;
        int num_prob = 9;
        int rand_c = rand() % num_prob;

        if (rand_c <= 1) {
                *cptr = 'S';
        } else if (rand_c <= 3) {
                *cptr = 'Z';
        } else if (rand_c == 4) {
                *cptr = 'I';
        } else if (rand_c == 5) {
                *cptr = 'J';
        } else if (rand_c == 6) {
                *cptr = 'L';
        } else if (rand_c == 7) {
                *cptr = 'O';
        } else if (rand_c == 8) {
                *cptr = 'T';
        }

        return cptr;
}



