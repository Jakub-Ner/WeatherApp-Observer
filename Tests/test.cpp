#include "../shit.h"
#include "gtest/gtest.h"

namespace {

    TEST(FactorialTest, Negative) {
        EXPECT_EQ(1, Factorial(-6));
    }

}
