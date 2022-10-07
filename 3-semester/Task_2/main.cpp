#include <iostream>
#include <vector>


#include "source.h"


int main() {
    std::vector <int> a = {1, 2, 3, 4, 5};
    std::vector <int> b = {1, 2, 3};

    std::vector <int> c = Merge(a, b);
    for (auto &elem : c)
        std::cout << elem << " ";
    return 0;
}
