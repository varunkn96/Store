#ifndef URNG_H
#define URNG_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

/*
 *  Generates unique random numbers between 1000 and 2000
 */
class UniqueRandomNumberGenerator {
    private:
        static const int MINIMUM = 1000;
        static const int MAXIMUM = 2000;
        static const int RANGE = MAXIMUM - MINIMUM;
        bool used[RANGE];
    public:
        UniqueRandomNumberGenerator();
        UniqueRandomNumberGenerator(vector<int>& used_ids);
        int generate();
};
#endif// URNG_H