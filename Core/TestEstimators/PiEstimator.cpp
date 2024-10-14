// Core/TestEstimators/PiEstimator.cpp
#include "PiEstimator.h"

PiEstimator::PiEstimator(
    const SimulationParameters& params,
    std::unique_ptr<RandomNumberGenerator> rng)
    : params_(params), rng_(std::move(rng)), uniformDist_(0.0, 1.0) {}

SimulationResult PiEstimator::estimatePi() {
    std::function<double()> simulationFunction = [this]() -> double {
        // Original Sample
        double x = uniformDist_.sample(*rng_);
        double y = uniformDist_.sample(*rng_);

        bool isInsideOriginal = (x * x + y * y <= 1.0);
        double resultOriginal = isInsideOriginal ? 4.0 : 0.0;

        // Antithetic Sample
        double x_anti = 1.0 - x;
        double y_anti = 1.0 - y;

        bool isInsideAntithetic = (x_anti * x_anti + y_anti * y_anti <= 1.0);
        double resultAntithetic = isInsideAntithetic ? 4.0 : 0.0;

        // Average the results
        return (resultOriginal + resultAntithetic) / 2.0;
    };

    MonteCarloSimulator simulator(params_, simulationFunction);
    return simulator.runSimulation();
}
