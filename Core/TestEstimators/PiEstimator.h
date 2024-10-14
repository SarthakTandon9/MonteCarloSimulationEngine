// Core/TestEstimators/PiEstimator.h
#ifndef PI_ESTIMATOR_H
#define PI_ESTIMATOR_H

#include "../Simulation/MonteCarloSimulator.h"
#include "../RandomNumberGenerator/RandomNumberGenerator.h"
#include "../RandomNumberGenerator/MersenneTwister.h"
#include "../Distribution/UniformDistribution.h"
#include "../StochasticProcess/SimulationParameters.h"
#include "../Simulation/SimulationResult.h"
#include <memory>
#include <functional>

class PiEstimator {
public:
    PiEstimator(
        const SimulationParameters& params,
        std::unique_ptr<RandomNumberGenerator> rng);

    SimulationResult estimatePi();

private:
    SimulationParameters params_;
    std::unique_ptr<RandomNumberGenerator> rng_;
    UniformDistribution uniformDist_;
};

#endif // PI_ESTIMATOR_H
