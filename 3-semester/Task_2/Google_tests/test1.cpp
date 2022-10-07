#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"

std::vector <int> ExpectedUnique(std::vector <int> array)
{
    std::vector <int> a = array;
    std::sort(a.begin(), a.end());
    a.erase(std::unique(begin(a), end(a)), end(a));

    std::vector <int> res;
    for (auto &elem : array)
    {
        for (int i = 0; i < a.size(); i++)
            if (a[i] == elem)
            {
                res.push_back(elem);
                a.erase(a.begin() + i);
                break;
            }

        if (a.empty())
            break;
    }

    return res;
}



TEST(UNIQUE_test_1, general_case)
{
    std::vector <int> a = {1, 2, 3, 1, 2, 3};

    ASSERT_EQ(ExpectedUnique(a) == delRepeating(a), true);
}

TEST(UNIQUE_test_2, all_equal)
{
    std::vector <int> a = {1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(ExpectedUnique(a) == delRepeating(a), true);
}

TEST(UNIQUE_test_3, all_different)
{
    std::vector <int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQ(ExpectedUnique(a) == delRepeating(a), true);
}

TEST(SEARCH_test_1, all_different)
{
    std::vector <int> a = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    int item = 5;
    ASSERT_EQ(binarySearch(a, item), 4);
}

TEST(SEARCH_test_2, no_element)
{
    std::vector <int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int item = 10;
    ASSERT_EQ(binarySearch(a, item), -1);
}

TEST(MERGING_test_1, same_array)
{
    std::vector <int> a = {1, 2, 3};
    std::vector <int> b = {1, 2, 3};

    std::vector <int> expected = a;
    for (auto &elem : b) expected.push_back(elem);
    sort(expected.begin(), expected.end());

    ASSERT_EQ(Merge(a, b) == expected, true);
}

TEST(MERGING_test_2, one_is_longer)
{
    std::vector <int> a = {1, 2, 3, 4, 5};
    std::vector <int> b = {1, 2, 3};

    std::vector <int> expected = a;
    for (auto &elem : b) expected.push_back(elem);
    sort(expected.begin(), expected.end());

    ASSERT_EQ(Merge(a, b) == expected, true);
}

TEST(MERGING_test_3, one_is_empty)
{
    std::vector <int> a = {1, 2, 3, 4, 5};
    std::vector <int> b = {};

    std::vector <int> expected = a;
    for (auto &elem : b) expected.push_back(elem);
    sort(expected.begin(), expected.end());

    ASSERT_EQ(Merge(a, b) == expected, true);
}

