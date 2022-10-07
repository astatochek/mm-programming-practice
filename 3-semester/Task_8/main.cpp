#include <iostream>
#include "source.h"



int main() {

    std::vector <Polynom> VictorPolynomov = Chebyshev2(10);

    for (auto &elem : VictorPolynomov)
        std::cout << elem << "\n";

}
