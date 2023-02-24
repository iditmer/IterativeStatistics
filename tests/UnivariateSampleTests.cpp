
#include <gtest/gtest.h>
#include <vector>
#include "UnivariateSample.hpp"

class UnivariateSampleTest : public ::testing::Test {

protected:

    UnivariateSample no_items{ true, false };
};

TEST_F(UnivariateSampleTest, Count) {
    EXPECT_EQ(no_items.Count(), 0);
}