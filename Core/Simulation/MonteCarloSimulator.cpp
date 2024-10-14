// Core/Simulation/MonteCarloSimulator.cpp
#include "MonteCarloSimulator.h"
#include <cmath>
#include <limits>
#include <iostream>

MonteCarloSimulator::MonteCarloSimulator(
    const SimulationParameters& params,
    std::function<double()> simulationFunction,
    VarianceReduction::VarianceReductionTechnique* varianceReduction)
    : params_(params), simulationFunction_(simulationFunction), varianceReduction_(varianceReduction) {}

SimulationResult MonteCarloSimulator::runSimulation() {
    double mean = 0.0;
    double M2 = 0.0;
    int n = 0;

    for (int i = 0; i < params_.numSteps; ++i) {
        double result = simulationFunction_();

        // Ensure the result is a valid number
        if (std::isnan(result) || std::isinf(result)) {
            std::cout << "Nan value encountered" << std::endl;
            continue; // For simplicity, we'll skip invalid results
        }

        n += 1;
        double delta = result - mean;
        mean += delta / n;
        double delta2 = result - mean;
        M2 += delta * delta2;
    }

    SimulationResult simResult;

    if (n < 2) {
        // Not enough data to compute variance
        simResult.estimatedValue = mean;
        simResult.variance = 0.0;
        simResult.standardError = 0.0;
    } else {
        // Population variance
        simResult.variance = M2 / (n - 1);
        simResult.standardError = std::sqrt(simResult.variance / n);
        simResult.estimatedValue = mean;
    }

    return simResult;
}
