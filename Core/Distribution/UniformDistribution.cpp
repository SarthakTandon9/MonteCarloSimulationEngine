#include "UniformDistribution.h"
#include <iostream>
#include <vector>
#include <string>

UniformDistribution::UniformDistribution(double lower_, double upper_) : lower(lower_), upper(upper_)
{
    if(upper <= lower)
    {
        throw std::invalid_argument("Upper bound must be greater than lower bound in UniformDistribution.");
    }
}

double UniformDistribution::sample(RandomNumberGenerator& rng)
{
    double u = rng.next();
    return lower + u * (upper - lower);
}