
#include <gtest/gtest.h>
#include "UnivariateSample.hpp"

class UnivariateSampleTest : public ::testing::Test {

protected:

    UnivariateSample no_items{};
    UnivariateSample single_item{};
    
    const double single_item_value = 3.1415926535;
    
    void SetUp() override {

        single_item.Update(single_item_value);
    }
};

TEST_F(UnivariateSampleTest, Count) {
    EXPECT_EQ(no_items.Count(), 0);
    EXPECT_EQ(single_item.Count(), 1);
}

TEST_F(UnivariateSampleTest, Mean) {
    EXPECT_THROW(no_items.Mean(), std::logic_error);
    EXPECT_EQ(single_item.Mean(), single_item_value);
}