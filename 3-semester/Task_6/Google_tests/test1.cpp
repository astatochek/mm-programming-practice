#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"
#include <fstream>
#include <utility>


TEST(Sklad_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_6/test1.txt";
    std::ifstream in(path);
    std::stringstream myString;
    std::string line;
    if (in.is_open())
        while (getline(in, line))
        { myString << line << "\n"; }

    int n, k, val1, val2;
    myString >> n >> k;
    std::vector< std::pair <float, std::pair<int,int> > > v;
    while(n--)
    {
        myString >> val1 >> val2;
        v.push_back(std::make_pair((float) val2 / (float) val1, std::make_pair(val1, val2)));
    }

    std::pair <int, int> actual = Sklad(v, k);

    ASSERT_EQ(actual == std::make_pair(261, 910), true);
}


TEST(Dict_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_6/test2.txt";
    std::string actual = Who(path);

    ASSERT_EQ(actual, "Bye");
}




