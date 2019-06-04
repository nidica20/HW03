#include <stdexcept>
#include <fstream>
#include <iostream>
#include "readint.h"
#include "gtest/gtest.h"
#include <sstream>
using namespace std;
// Remember to include in unittest1.cpp

TEST(ReadIntTest, InvalidArg2)
{
    auto func = []()
    {
        //Call with incorrect arguments (test case 2)
        read_int("My prompt: ", 5, 1);
    };
    ASSERT_THROW(func(), std::invalid_argument);
}

TEST(ReadIntTest, InvalidArg4)
{
    auto func = []()
    {
        //Call with incorrect arguments (test case 4)
        read_int("My prompt: ", 0, 0);
    };
    ASSERT_THROW(func(), std::invalid_argument);
}

TEST(ReadIntTest, zeroinput)
{
    ifstream ss("tests\\zeroinput.txt");
    if (ss.fail()) 
    {
        throw int(-1);
    }
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    ASSERT_EQ(read_int("My prompt: ", -3, 3), 0);
    ss.close();
}

TEST(ReadIntTest, threeinput)
{
    istringstream ss("-3\n5\n10\n-3\n3");
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    ASSERT_EQ(read_int("My prompt: ", 0, 4), 3);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

