#ifndef EXPONENTIAL_DISTRIBUTION_H
#define EXPONENTIAL_DISTRIBUTION_H

#include "Distribution.h"
#include<cmath>

class ExponentialDistribution : public Distribution
{
    private:
        double lambda;
    public:
        ExponentialDistribution(double lambda_ = 1.0);
        double sample(RandomNumberGenerator& rng) override;
};

#endif