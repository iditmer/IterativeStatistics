
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Constants.hpp"
#include "MultivariateSample.hpp"

using ::testing::Pointwise;
using ::testing::DoubleNear;

class MultivariateSampleTest : public ::testing::Test {

protected:

    MultivariateSample no_items{ multivariate_no_item_dim, true };
    
    MultivariateSample single_item{ multivariate_single_item_dim, false };
    MultivariateSample single_item_with_variance{ multivariate_single_item_dim, true };
    
    MultivariateSample multiple_items{ multivariate_multiple_item_dim, false };
    MultivariateSample multiple_items_with_variance{ multivariate_multiple_item_dim, true };

    void SetUp() override {

        single_item.Update(multivariate_single_item_value);
        single_item_with_variance.Update(multivariate_single_item_value);

        for (const auto& row : multivariate_multiple_item_values) {
            multiple_items.Update(row);
            multiple_items_with_variance.Update(row);
        }
    }
};

TEST_F(MultivariateSampleTest, Count) {
    ASSERT_EQ(no_items.Count(), 0);
    ASSERT_EQ(single_item.Count(), 1);
    ASSERT_EQ(single_item_with_variance.Count(), 1);
    ASSERT_EQ(multiple_items.Count(), multivariate_multiple_item_values.size());
    ASSERT_EQ(multiple_items_with_variance.Count(), multivariate_multiple_item_values.size());
}

TEST_F(MultivariateSampleTest, Dimensionality) {
    ASSERT_EQ(no_items.Dimensionality(), multivariate_no_item_dim);
    ASSERT_EQ(single_item.Dimensionality(), multivariate_single_item_dim);
    ASSERT_EQ(single_item_with_variance.Dimensionality(), multivariate_single_item_dim);
    ASSERT_EQ(multiple_items.Dimensionality(), multivariate_multiple_item_dim);
    ASSERT_EQ(multiple_items_with_variance.Dimensionality(), multivariate_multiple_item_dim);
}

TEST_F(MultivariateSampleTest, Mean) {
    ASSERT_THROW(no_items.Mean(), std::logic_error);
    ASSERT_EQ(single_item.Mean(), multivariate_single_item_value);
    ASSERT_EQ(single_item_with_variance.Mean(), multivariate_single_item_value);
    ASSERT_THAT(multiple_items.Mean(), Pointwise(DoubleNear(1e-11), multivariate_multiple_item_mean));
    ASSERT_THAT(multiple_items_with_variance.Mean(), Pointwise(DoubleNear(1e-11), multivariate_multiple_item_mean));
}

TEST_F(MultivariateSampleTest, Covariance) {
    
}