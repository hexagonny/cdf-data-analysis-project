#ifndef RANDVAR_H
#define RANDVAR_H

#include <iostream>
#include <vector>

struct RandomVariable {
protected:
    std::vector<int> frequencies;
    int sum_f;
    int n;

public:
    void setFrequencies(const std::vector<int>& newFrequencies) {
        frequencies = newFrequencies;
        
        sum_f = 0;
        for (int f : frequencies) {
            sum_f += f;
        }
    }
    std::vector<int> getFrequencies() const { return frequencies; }
    int              getSum_f()       const { return sum_f; }
    int              getTotal_X()     const { return n; }

    void inputFrequency();
    void debugPrint();
};

extern RandomVariable rv;

#endif