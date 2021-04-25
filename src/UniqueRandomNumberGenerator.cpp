#include <iostream>
#include "UniqueRandomNumberGenerator.h"

using namespace std;

UniqueRandomNumberGenerator::UniqueRandomNumberGenerator() { }

UniqueRandomNumberGenerator::UniqueRandomNumberGenerator(vector<int>& used_ids) {
    srand(time(NULL));
    for(int i=0; i < RANGE; ++i) {
        used[i] = false;
    }
    for(int i=0; i < used_ids.size(); ++i) {
        used[used_ids[i] - MINIMUM] = true;
    }
}

int UniqueRandomNumberGenerator::generate() {
    int next_id;
    do {
        next_id = (rand() % RANGE) + MINIMUM;
    } while (used[next_id - MINIMUM]);
    return next_id;
}