#include "NormalDistribution.h"
#include<cmath>
#define M_PI 3.1415926535

NormalDistribution::NormalDistribution(double mean_, double stdev_) : mean(mean_), stdev(stdev_)
{}


double NormalDistribution::sample(RandomNumberGenerator& rng)
{
    double u1 = rng.next();
    double u2 = rng.next();

    if(u1 <= 0.0)
    {
        u1 = 1e-10;
    }

    double z_0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
    return z_0*stdev + mean;
}