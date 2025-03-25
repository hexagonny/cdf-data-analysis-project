#ifndef PROBABILITY_H
#define PROBABILITY_H

#include "random_variable.h"

struct Probability: public RandomVariable {
private: 
    std::vector<double> probabilities;
    std::vector<double> cdf;
    double sum_P;

public:
    std::vector<double> getProbabilities() const { return probabilities; }
    std::vector<double> getCDF()           const { return cdf; }
    int                 getSum_P()         const { return sum_P; }

    void setProbabilities();
    void setCDF();
    void debugPrint();
};

extern Probability P;

#endif