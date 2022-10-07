#include <iostream>
#include "source.h"
#include <list>


int main() {

    std::vector <double> v = {234, 2, 5, 54, 5};
    std::vector <std::pair <int, int> > res = sortDivideWin(v);

    for (auto &elem : res)
        std::cout << elem.first << " " << elem.second << "\n";

    return 0;
}
