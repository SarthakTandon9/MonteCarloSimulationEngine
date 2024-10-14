#ifndef UNIFORM_DISTRIBUTION_H
#define UNIFORM_DISTRIBUTION_H

#include "Distribution.h"


class UniformDistribution : public Distribution
{
    private:
        double lower;
        double upper;
    public:
        UniformDistribution(double lower = 0.0, double upper = 1.0);
        double sample(RandomNumberGenerator& rng) override;
};

#endif