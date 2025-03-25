#include <iostream>
#include <vector>

struct RandomVariable {
protected:
    std::vector<int> frequencies;
    int sum_f;

public:
    void inputFrequencies()
    {
        int n;
        std::cout << "Enter number of values: ";
        std::cin >> n;
        frequencies.resize(n);
        
        sum_f = 0;

        std::cout << "Enter frequencies:\n";
        for(int i = 0; i < n; i++) {
            std::cout << "Frequency" << i + 1 << ": ";
            std::cin >> frequencies[i];
            sum_f += frequencies[i];
        }
    }

    void print()
    {
        {
            if(frequencies.empty()) return;

            std::cout << "\nFrequency of X:\n";
            for(int frequency : frequencies) {
                std::cout << frequency << '\n';
            }
            std::cout << "\nSum of frequencies: " << sum_f << "\n\n";
        }
    }
};

struct Probability : public RandomVariable {
private:
    std::vector<double> probabilities;
    std::vector<double> cdf;
public:
    void setProbabilities()
    {
        if (sum_f == 0) {
            std::cerr << "Error: summation is zero, division by zero avoided!\n";
            return;
        }

        probabilities.clear();
        for(int frequency : frequencies) {
            double probability = static_cast<double>(frequency) / sum_f;
            probabilities.push_back(probability);
        }
    }

    void setCDF()
    {
        if(probabilities.empty()){
            std::cerr << "Error: probability is empty!\n";
            return;
        }

        double cumulitative;
        for(double probability : probabilities){
            cumulitative += probability;
            cdf.push_back(cumulitative);
        }
    }

    void print()
    {
        if(probabilities.empty()) return;

        double sum_P;

        std::cout << "Probability:\n";
        for(double probability : probabilities) {
            std::cout << probability << '\n';
        }
        
        std::cout << "\nCDF:\n";
        for(double cumulitative : cdf) {
            std::cout << cumulitative << '\n';
        }
    }
};

int main()
{   
    Probability P;
    P.inputFrequencies();
    P.RandomVariable::print();
    P.setProbabilities();
    P.setCDF();
    P.print();

    return 0;
}