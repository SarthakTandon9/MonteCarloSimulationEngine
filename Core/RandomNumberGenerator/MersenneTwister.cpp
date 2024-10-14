#include "MersenneTwister.h"
using namespace std;

MersenneTwister::MersenneTwister(unsigned int seed):
    engine(seed), dist(0.0, 1.0) {}

double MersenneTwister::next()
{
    return dist(engine);
}



