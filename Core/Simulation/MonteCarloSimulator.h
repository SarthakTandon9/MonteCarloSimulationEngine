// Core/Simulation/MonteCarloSimulator.h
#ifndef MONTE_CARLO_SIMULATOR_H
#define MONTE_CARLO_SIMULATOR_H

#include "../StochasticProcess/SimulationParameters.h"
#include "SimulationResult.h"
#include "../VarianceReduction/VarianceReductionTechnique.h"
#include <functional>

class MonteCarloSimulator {
public:
    MonteCarloSimulator(
        const SimulationParameters& params,
        std::function<double()> simulationFunction,
        VarianceReduction::VarianceReductionTechnique* varianceReduction = nullptr);

    SimulationResult runSimulation();

private:
    SimulationParameters params_;
    std::function<double()> simulationFunction_;
    VarianceReduction::VarianceReductionTechnique* varianceReduction_;
};

#endif // MONTE_CARLO_SIMULATOR_H
