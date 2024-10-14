#ifndef STOCHASTIC_PROCESS_H
#define STOCHASTIC_PROCESS_H

#include "../RandomNumberGenerator/RandomNumberGenerator.h"
#include "../Distribution/Distribution.h"
#include "SimulationParameters.h"
#include <vector>

class StochasticProcess
{
    public:
        virtual void simulate(RandomNumberGenerator& rng, const SimulationParameters& params, std::vector<double>& path) = 0;
        virtual ~StochasticProcess(){}
};


#endif