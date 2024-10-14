#include "GeometricBrownianMotion.h"
#include <cmath>
#include <stdexcept>
#include "C:\Users\sarth\OneDrive\Desktop\Purdue\Projects\MonteCarlo\Core\Distribution\NormalDistribution.h"

GeometricBrownianMotion::GeometricBrownianMotion(double drift_, double volatality_) : drift(drift_), volatality(volatality_)
{
    if(volatality <= 0.0)
    {
        throw std::invalid_argument("Volatility must be positive in GeometricBrownianMotion.");
    }

}

void GeometricBrownianMotion::simulate(RandomNumberGenerator& rng, const SimulationParameters& params, std::vector<double>& path)
{
    if (params.numSteps <= 0) {
        throw std::invalid_argument("Number of steps must be positive in SimulationParameters.");
    }
    if (params.timeToMaturity <= 0.0) {
        throw std::invalid_argument("Time to maturity must be positive in SimulationParameters.");
    }
    if (params.initialValue <= 0.0) {
        throw std::invalid_argument("Initial value must be positive in SimulationParameters.");
    }

    double dt = params.timeToMaturity / params.numSteps;

    path.resize(params.numSteps + 1);

    path[0] = params.initialValue;

    NormalDistribution normalDist(0.0, 1.0);

    for(int i = 1; i <= params.numSteps; i++)
    {
        double Z = normalDist.sample(rng);
        double S_prev = path[i - 1];
        double S_new = S_prev * std::exp((drift - 0.5 * volatality * volatality) * dt + volatality * std::sqrt(dt) * Z);
        path[i] = S_new;
    }
}