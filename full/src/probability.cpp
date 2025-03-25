#include "random_variable.h"
#include "probability.h"

Probability P;

void Probability::setProbabilities()
{
    if(getSum_f() == 0){
        std::cerr << "Error: summation is zero, division by zero avoided!\n";
        return;
    }

    getProbabilities().clear();
    for(int frequency : getFrequencies()){
        double probability = static_cast<double>(frequency) / getSum_f();
        probabilities.push_back(probability);
    }
}

void Probability::debugPrint()
{
    if(probabilities.empty()) return;

    std::cout << "\nProbability:\n";
    for(double probability : probabilities){
        std::cout<< probability << '\n';
        sum_P += probability;
    }
    std::cout << "Sum of probability: " << sum_P << "\n\n";

    std::cout << "Cumulitative Distribution:\n";
    for(double cumulitative : cdf) {
        std::cout << cumulitative << '\n';
    }

}