#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "C:\Users\sarth\OneDrive\Desktop\Purdue\Projects\MonteCarlo\Core\RandomNumberGenerator\MersenneTwister.h"

class Distribution
{
    public:
        virtual double sample(RandomNumberGenerator& rng) = 0;
        virtual ~Distribution(){}
};
#endif