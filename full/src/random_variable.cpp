#include <iostream>
#include <vector>
#include <limits>

#include "random_variable.h"

RandomVariable rv;

void RandomVariable::inputFrequency()
{
    std::cout << "Enter number of values: ";
    std::cin >> n;
    
    std::vector<int> temp(n);
    int value;

    std::cout << "\nEnter frequencies:\n";
    for(int i = 0; i < n; i++) {
        std::cout << "Frequency " << i + 1 << ": ";
        while (true){
            std::cin >> value;
            if(std::cin.fail() || value < 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a non-negative number!\n";
            }
            else{
                break;
            }
        }
        temp[i] = value;
    }

    setFrequencies(temp);
}

void RandomVariable::debugPrint()
{
    {
        if(frequencies.empty()) return;

        std::cout << "\nFrequency of X\n";
        for(int frequency : frequencies) {
            std::cout << frequency << '\n';
        }
        std::cout << "\nSum of frequencies: " << sum_f << "\n";
    }
}