#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"





TEST(EmplaceE_test_1, basic_test)
{
    std::list <int> actual = {1, 2, 3, 4, 1, 2, 3, 4};
    emplaceE(actual, 1, 5);
    std::list <int> expected = {1, 5, 2, 3, 4, 1, 5, 2, 3, 4};

    ASSERT_EQ(actual, expected);
}

TEST(EmplaceE_test_1, no_change)
{
    std::list <int> actual = {1, 2, 3, 4, 1, 2, 3, 4};
    emplaceE(actual, 5, 6);
    std::list <int> expected = {1, 2, 3, 4, 1, 2, 3, 4};

    ASSERT_EQ(actual, expected);
}




