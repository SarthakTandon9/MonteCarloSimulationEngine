#include "ExponentialDistribution.h"
#include <vector>
#include<iostream>


ExponentialDistribution::ExponentialDistribution(double lambda_) : lambda(lambda_)
{
    if(lambda <= 0.0)
    {
        throw std::invalid_argument("Lambda must be positive");
    }
}

double ExponentialDistribution::sample(RandomNumberGenerator& rng)
{
    double u = rng.next();
    if(u <= 0.0)
    {
        u = 1e-10;
    }
    return -std::log(u) / lambda;
}