// Core/VarianceReduction/AntitheticVariates.cpp
#include "AntitheticVariates.h"

namespace VarianceReduction {

AntitheticVariates::AntitheticVariates() : generateAntithetic_(false), lastSample_(0.0) {}

void AntitheticVariates::apply(double& sample) {
    if (generateAntithetic_) {
        sample = 1.0 - lastSample_;
        generateAntithetic_ = false;
    } else {
        lastSample_ = sample;
        generateAntithetic_ = true;
    }
}

}
