#ifndef MERSENNE_TWISTER_H
#define MERSENNE_TWISTER_H

#include "RandomNumberGenerator.h"
#include <random>

using namespace std;

class MersenneTwister : public RandomNumberGenerator
{
    private:
        mt19937 engine;
        uniform_real_distribution<double> dist;

    public:
        MersenneTwister(unsigned int seed = random_device{}());
        double next() override;
        
};


#endif