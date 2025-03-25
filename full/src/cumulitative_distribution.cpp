#include "probability.h"

void Probability::setCDF()
{
    if(getProbabilities().empty()){
        std::cerr << "Error: probability is empty!\n";
        return;
    }

    double cumulitative;
    for(double probability : getProbabilities()){
        cumulitative += probability;
        cdf.push_back(cumulitative);
    }
}