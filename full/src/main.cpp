#include <iostream>

#include "hutils.h"
#include "probability.h"
#include "random_variable.h"

int main()
{
    hUtils::setConsoleWindowSize(); hUtils::text.clearAll();
    
    P.inputFrequency();
    hUtils::text.clearAll();
    P.setProbabilities();
    P.setCDF();

    hUtils::text.toLine();

    std::cout << "f(X):   ";
    hUtils::table.setElements(P.getFrequencies());
    hUtils::table.toColumn("left", 12, P.getTotal_X());

    hUtils::text.toLine();

    std::cout << "P(X):   ";
    hUtils::table.setElements(P.getProbabilities());
    hUtils::table.toColumn("left", 12, P.getTotal_X());

    hUtils::text.toLine();

    std::cout << "F(X):   ";
    hUtils::table.setElements(P.getCDF());
    hUtils::table.toColumn("left", 12, P.getTotal_X());

    hUtils::pause();

    return 0;
}