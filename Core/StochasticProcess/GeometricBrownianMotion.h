#ifndef GEOMETRIC_BROWNIAN_MOTION_H
#define GEOMETRIC_BROWNIAN_MOTION_H

#include "StochasticProcess.h"

class GeometricBrownianMotion : public StochasticProcess
{
    private:
        double drift;
        double volatality;
    public:
        GeometricBrownianMotion(double drift_ = 0.1, double volatility_ = 0.2);
        void simulate(RandomNumberGenerator& rng, const SimulationParameters& params, std::vector<double>& path) override;

};
#endif

