//tests/test_mytype.cpp
#include "gtest/gtest.h"
#include "my_type.h"
#include <fstream>
using namespace Session_13_14_15;
TEST(MyType, WriteRead){
    MyType mt(42,3.14);
    writeToFile(mt,"mytype.txt");
    auto mt2 = readFromFile("mytype.txt");
    ASSERT_EQ(mt,mt2);
}
