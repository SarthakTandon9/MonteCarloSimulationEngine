#ifndef NORMAL_DISTRIBTION_H
#define NORMAL_DISTRIBTION_H

#include "Distribution.h"
#include<cmath>

class NormalDistribution : public Distribution
{
    private:
        double mean;
        double stdev;

    public:
        NormalDistribution(double mean = 0.0, double stdev = 1.0);
        double sample(RandomNumberGenerator& rng) override;
};

#endif