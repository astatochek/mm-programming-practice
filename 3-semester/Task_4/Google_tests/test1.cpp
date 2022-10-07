#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include "source.h"




TEST(AnormalLine_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text1.txt";

    std::string expected = "Prosto zdravstvuyte prost dosvidanya.";

    std::string actual = getNormalLineA(path);

    ASSERT_EQ(actual, expected);
}

TEST(AnormalLine_test_2, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text2.txt";

    std::string expected = "df dfgdfg df asd df.";

    std::string actual = getNormalLineA(path);

    ASSERT_EQ(actual, expected);
}

TEST(AnormalLine_test_3, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text4.txt";

    std::string expected = "";

    std::string actual = getNormalLineA(path);

    ASSERT_EQ(actual, expected);
}

TEST(AnormalLine_test_4, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text5.txt";

    std::string expected = "";

    std::string actual = getNormalLineA(path);

    ASSERT_EQ(actual, expected);
}

TEST(BnormalLine_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text1.txt";

    std::string expected = "Prosto zdravstvuyte prost dosvidanya.";

    std::string actual = getNormalLineB(path);

    ASSERT_EQ(actual, expected);
}

TEST(BnormalLine_test_2, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text2.txt";

    std::string expected = "df dfgdfg df asd df.";

    std::string actual = getNormalLineB(path);

    ASSERT_EQ(actual, expected);
}

TEST(BnormalLine_test_3, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text4.txt";

    std::string expected = "";

    std::string actual = getNormalLineB(path);

    ASSERT_EQ(actual, expected);
}

TEST(BnormalLine_test_4, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text5.txt";

    std::string expected = "";

    std::string actual = getNormalLineB(path);

    ASSERT_EQ(actual, expected);
}

TEST(abnormalLine_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text2.txt";

    std::string expected = "dfgdfg asd";

    std::string actual = getAbnormalLine(path);

    ASSERT_EQ(actual, expected);
}

TEST(abnormalLine_test_2, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text7.txt";

    std::string expected = "";

    std::string actual = getAbnormalLine(path);

    ASSERT_EQ(actual, expected);
}

TEST(delLastLetter_test_1, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text3.txt";

    std::string expected = "a ab abc abcd";

    std::string actual = delLastLetter(path);

    ASSERT_EQ(actual, expected);
}

TEST(delLastLetter_test_2, basic_test)
{
    std::string path = "C:/Users/ASUS/CLionProjects/Task_4/text6.txt";

    std::string expected = "";

    std::string actual = delLastLetter(path);

    ASSERT_EQ(actual, expected);
}





