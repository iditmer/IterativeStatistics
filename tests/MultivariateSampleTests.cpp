
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Constants.hpp"
#include "MultivariateSample.hpp"

using ::testing::Pointwise;
using ::testing::DoubleNear;

class MultivariateSampleTest : public ::testing::Test {

protected:

    MultivariateSample no_items{ 2 };
    MultivariateSample single_item{ 4 };
    MultivariateSample multiple_items{ 7 };

    void SetUp() override {
        single_item.Update(multivariate_single_item_value);
        
        for (auto& row : multivariate_multiple_item_values) {
            multiple_items.Update(row);
        }
    }
};

TEST_F(MultivariateSampleTest, Count) {
    ASSERT_EQ(no_items.Count(), 0);
    ASSERT_EQ(single_item.Count(), 1);
    ASSERT_EQ(multiple_items.Count(), multivariate_multiple_item_values.size());
}

TEST_F(MultivariateSampleTest, Dimensionality) {
    ASSERT_EQ(no_items.Dimensionality(), 2);
    ASSERT_EQ(single_item.Dimensionality(), 4);
    ASSERT_EQ(multiple_items.Dimensionality(), 7);
}

TEST_F(MultivariateSampleTest, Mean) {
    ASSERT_THROW(no_items.Mean(), std::logic_error);
    ASSERT_EQ(single_item.Mean(), multivariate_single_item_value);
    ASSERT_THAT(multiple_items.Mean(), Pointwise(DoubleNear(1e-11), multivariate_multiple_item_mean));
}