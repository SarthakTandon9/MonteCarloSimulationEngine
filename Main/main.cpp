// Main/main.cpp
#include <iostream>
#include "../Core/StochasticProcess/SimulationParameters.h"
#include "../Core/RandomNumberGenerator/MersenneTwister.h"
#include "../Core/TestEstimators/PiEstimator.h"

int main() {
    SimulationParameters params;
    params.numSteps = 1000000000;      // Number of simulation steps
    params.initialValue = 0.0;      // Not used in Pi estimation
    params.timeToMaturity = 0.0;    // Not used in Pi estimation

    auto rng = std::make_unique<MersenneTwister>();

    PiEstimator estimator(params, std::move(rng));

    SimulationResult result = estimator.estimatePi();

    std::cout << "Estimated Pi: " << result.estimatedValue << std::endl;
    std::cout << "Standard Error: " << result.standardError << std::endl;

    return 0;
}
