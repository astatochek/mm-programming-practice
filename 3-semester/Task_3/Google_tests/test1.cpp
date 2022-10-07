#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"




TEST(To2Dimansions_test_1, n_n)
{
    std::vector <int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector <std::vector <int> > expected = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    ASSERT_EQ(to2D(a, 3, 3) == expected, true);
}

TEST(To2Dimansions_test_2, m_n)
{
    std::vector <int> a = {1, 2, 3, 4, 5, 6};
    std::vector <std::vector <int> > expected = {
            {1, 2, 3},
            {4, 5, 6}
    };
    ASSERT_EQ(to2D(a, 3, 2) == expected, true);
}

TEST(To1Dimansion_test_1, n_n)
{
    std::vector <std::vector <int> > a = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    std::vector <int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(to1D(a) == expected, true);
}

TEST(To1Dimansion_test_2, m_n)
{
    std::vector <std::vector <int> > a = {
            {1, 2, 3},
            {4, 5, 6}
    };
    std::vector <int> expected = {1, 2, 3, 4, 5, 6};

    ASSERT_EQ(to1D(a) == expected, true);
}

TEST(determinant_test_1, not_zero)
{
    std::vector <std::vector <double> > arr = {
            {1, 2, 3, 4, 5, 6, 7},
            {34, 4, 5, 7, 2, 1, 3},
            {56, 7, -34, -45, -3, -5, 4},
            {5, 3, 2, 4, 1, 2, 7},
            {4, 5, 67, 2, 1, 5, 6},
            {3, 6, 2, 4, 5, 6, 27},
            {2, 1, -10, 6, 5, 0, 9}
    };
    matrix a(arr);
    ASSERT_EQ(det(a), -59745860);
}

TEST(determinant_test_2, zero)
{
    std::vector <std::vector <double> > arr = {
            {0, 0, 0, 0, 0, 0, 0},
            {34, 4, 5, 7, 2, 1, 3},
            {56, 7, -34, -45, -3, -5, 4},
            {5, 3, 2, 4, 1, 2, 7},
            {4, 5, 67, 2, 1, 5, 6},
            {3, 6, 2, 4, 5, 6, 27},
            {2, 1, -10, 6, 5, 0, 9}
    };
    matrix a(arr);
    ASSERT_EQ(det(a), 0);
}

TEST(determinant_test_3, normal)
{
    std::vector <std::vector <double> > arr = {
            {1, 2, 3, 4},
            {5, 6, 10, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 20}
    };
    matrix a(arr);
    ASSERT_EQ(det(a), 96);
}




