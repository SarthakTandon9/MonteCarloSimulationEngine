// Core/VarianceReduction/AntitheticVariates.h
#ifndef ANTITHETIC_VARIATES_H
#define ANTITHETIC_VARIATES_H

#include "VarianceReductionTechnique.h"

namespace VarianceReduction {

class AntitheticVariates : public VarianceReductionTechnique {
public:
    AntitheticVariates();
    virtual ~AntitheticVariates() {}
    virtual void apply(double& sample) override;

private:
    bool generateAntithetic_;
    double lastSample_;
};

}

#endif // ANTITHETIC_VARIATES_H
