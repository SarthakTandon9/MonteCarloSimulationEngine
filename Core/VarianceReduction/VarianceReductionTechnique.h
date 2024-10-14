// Core/VarianceReduction/VarianceReductionTechnique.h
#ifndef VARIANCE_REDUCTION_TECHNIQUE_H
#define VARIANCE_REDUCTION_TECHNIQUE_H

namespace VarianceReduction {

class VarianceReductionTechnique {
public:
    virtual ~VarianceReductionTechnique() {}
    virtual void apply(double& sample) = 0;
};

}

#endif // VARIANCE_REDUCTION_TECHNIQUE_H
