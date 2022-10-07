#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"





TEST(Divide_test_1, basic_test)
{
    std::vector <double> v = {7, 2, 4};
    std::vector <std::pair <int, int> > actual = sortDivideWin(v);
    std::vector <std::pair <int, int> > expected = {
            std::make_pair(2, 3),
            std::make_pair(1, 4),
    };

    ASSERT_EQ(actual, expected);
}

TEST(Divide_test_2, basic_test)
{
    std::vector <double> v = {6, 2, 7, 1};
    std::vector <std::pair <int, int> > actual = sortDivideWin(v);
    std::vector <std::pair <int, int> > expected = {
            std::make_pair(2, 4),
            std::make_pair(1, 5),
            std::make_pair(3, 6),
    };

    ASSERT_EQ(actual, expected);
}

TEST(Divide_test_3, basic_test)
{
    std::vector <double> v = {12, 4, 7, 2};
    std::vector <std::pair <int, int> > actual = sortDivideWin(v);
    std::vector <std::pair <int, int> > expected = {
            std::make_pair(2, 4),
            std::make_pair(3, 5),
            std::make_pair(1, 6),
    };

    ASSERT_EQ(actual, expected);
}


TEST(Divide_test_4, basic_test)
{
    std::vector <double> v = {234, 2, 5, 54, 5};
    std::vector <std::pair <int, int> > actual = sortDivideWin(v);
    std::vector <std::pair <int, int> > expected = {
            std::make_pair(2, 3),
            std::make_pair(5, 6),
            std::make_pair(4, 7),
            std::make_pair(1, 8),
    };

    ASSERT_EQ(actual, expected);
}




