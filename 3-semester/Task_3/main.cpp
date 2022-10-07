#include <iostream>
#include <vector>


#include "source.h"


int main() {
    std::vector <std::vector <double> > a = {
            {0, 2, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 3, 0},
            {0, 0, 0, 4}
    };

    matrix b(a);

    for (int i = 0; i < b.M.size(); i++)
    {
        for (int j = 0; j < b.M[i].size(); j++)
        {
            std::cout << b.M[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Det: " << det(b) << std::endl;



    for (int i = 0; i < b.M.size(); i++)
    {
        for (int j = 0; j < b.M[i].size(); j++)
        {
            std::cout << b.M[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
