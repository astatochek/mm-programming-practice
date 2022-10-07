#include <iostream>
#include "source.h"
#include <list>


int main() {
    std::list <int> l = {1, 2, 3, 4, 1, 2, 3, 4};
    emplaceE(l, 1, 5);
    std::cout << l;

    return 0;
}
