#include <iostream>
#include <string>
#include "source.h"


int main() {
    int n, k, val1, val2;
    std::cin >> n >> k;
    std::vector< std::pair <float, std::pair<int,int> > > v;
    while(n--)
    {
        std::cin >> val1 >> val2;
        v.push_back(std::make_pair((float) val2 / (float) val1, std::make_pair(val1, val2)));
    }

    std::pair <int, int> res = Sklad(v, k);
    std::cout << res.first << " " << res.second;

    return 0;
}
