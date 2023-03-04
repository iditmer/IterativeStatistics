
#include <gtest/gtest.h>
#include "Constants.hpp"
#include "UnivariateSample.hpp"

class UnivariateSampleTest : public ::testing::Test {

protected:

    UnivariateSample no_items{ true, true };

    UnivariateSample single_item{ false, false };
    UnivariateSample single_item_with_variance{ true, false };
    UnivariateSample single_item_with_extrema{ false, true };
    UnivariateSample single_item_with_both{ true, true };
    
    UnivariateSample multiple_items{ false, false };
    UnivariateSample multiple_items_with_variance{ true, false };
    UnivariateSample multiple_items_with_extrema{ false, true };
    UnivariateSample multiple_items_with_both{ true,true };
    
    void SetUp() override {

        single_item.Update(univariate_single_item_value);
        single_item_with_variance.Update(univariate_single_item_value);
        single_item_with_extrema.Update(univariate_single_item_value);
        single_item_with_both.Update(univariate_single_item_value);

        for (auto& x : univariate_multiple_item_values) {
            multiple_items.Update(x);
            multiple_items_with_variance.Update(x);
            multiple_items_with_extrema.Update(x);
            multiple_items_with_both.Update(x);
        }
    }
};

TEST_F(UnivariateSampleTest, Count) {    
    ASSERT_EQ(no_items.Count(), 0);
    
    ASSERT_EQ(single_item.Count(), 1);
    ASSERT_EQ(single_item_with_variance.Count(), 1);
    ASSERT_EQ(single_item_with_extrema.Count(), 1);
    ASSERT_EQ(single_item_with_both.Count(), 1);
    
    ASSERT_EQ(multiple_items.Count(), univariate_multiple_item_values.size());
    ASSERT_EQ(multiple_items_with_variance.Count(), univariate_multiple_item_values.size());
    ASSERT_EQ(multiple_items_with_extrema.Count(), univariate_multiple_item_values.size());
    ASSERT_EQ(multiple_items_with_both.Count(), univariate_multiple_item_values.size());
}

TEST_F(UnivariateSampleTest, Mean) {
    ASSERT_THROW(no_items.Mean(), std::logic_error);

    ASSERT_EQ(single_item.Mean(), univariate_single_item_value);
    ASSERT_EQ(single_item_with_variance.Mean(), univariate_single_item_value);
    ASSERT_EQ(single_item_with_extrema.Mean(), univariate_single_item_value);
    ASSERT_EQ(single_item_with_both.Mean(), univariate_single_item_value);

    ASSERT_NEAR(multiple_items.Mean(), univariate_multiple_item_mean, 1e-12);
    ASSERT_NEAR(multiple_items_with_variance.Mean(), univariate_multiple_item_mean, 1e-12);
    ASSERT_NEAR(multiple_items_with_extrema.Mean(), univariate_multiple_item_mean, 1e-12);
    ASSERT_NEAR(multiple_items_with_both.Mean(), univariate_multiple_item_mean, 1e-12);
}

TEST_F(UnivariateSampleTest, Variance) {
    ASSERT_THROW(no_items.Variance(), std::logic_error);

    ASSERT_THROW(single_item.Variance(), std::logic_error);
    ASSERT_EQ(single_item_with_variance.Variance(), 0.0);
    ASSERT_THROW(single_item_with_extrema.Variance(), std::logic_error);
    ASSERT_EQ(single_item_with_both.Variance(), 0.0);

    ASSERT_THROW(multiple_items.Variance(), std::logic_error);
    ASSERT_NEAR(multiple_items_with_variance.Variance(), univariate_multiple_item_variance, 1e-7);
    ASSERT_THROW(multiple_items_with_extrema.Variance(), std::logic_error);
    ASSERT_NEAR(multiple_items_with_both.Variance(), univariate_multiple_item_variance, 1e-7);
}

TEST_F(UnivariateSampleTest, StandardDeviation) {
    ASSERT_THROW(no_items.StandardDeviation(), std::logic_error);

    ASSERT_THROW(single_item.StandardDeviation(), std::logic_error);
    ASSERT_EQ(single_item_with_variance.StandardDeviation(), 0.0);
    ASSERT_THROW(single_item_with_extrema.StandardDeviation(), std::logic_error);
    ASSERT_EQ(single_item_with_both.StandardDeviation(), 0.0);

    ASSERT_THROW(multiple_items.StandardDeviation(), std::logic_error);
    ASSERT_NEAR(multiple_items_with_variance.StandardDeviation(), univariate_multiple_item_standard_deviation, 1e-11);
    ASSERT_THROW(multiple_items_with_extrema.StandardDeviation(), std::logic_error);
    ASSERT_NEAR(multiple_items_with_both.StandardDeviation(), univariate_multiple_item_standard_deviation, 1e-12);
}

TEST_F(UnivariateSampleTest, Minimum) {
    ASSERT_THROW(no_items.Min(), std::logic_error);

    ASSERT_THROW(single_item.Min(), std::logic_error);
    ASSERT_THROW(single_item_with_variance.Min(), std::logic_error);
    ASSERT_EQ(single_item_with_extrema.Min(), univariate_single_item_value);
    ASSERT_EQ(single_item_with_both.Min(), univariate_single_item_value);

    ASSERT_THROW(multiple_items.Min(), std::logic_error);
    ASSERT_THROW(multiple_items_with_variance.Min(), std::logic_error);
    ASSERT_EQ(multiple_items_with_extrema.Min(), univariate_multiple_item_min);
    ASSERT_EQ(multiple_items_with_both.Min(), univariate_multiple_item_min);
}

TEST_F(UnivariateSampleTest, Maximum) {
    ASSERT_THROW(no_items.Max(), std::logic_error);

    ASSERT_THROW(single_item.Max(), std::logic_error);
    ASSERT_THROW(single_item_with_variance.Max(), std::logic_error);
    ASSERT_EQ(single_item_with_extrema.Max(), univariate_single_item_value);
    ASSERT_EQ(single_item_with_both.Max(), univariate_single_item_value);

    ASSERT_THROW(multiple_items.Max(), std::logic_error);
    ASSERT_THROW(multiple_items_with_variance.Max(), std::logic_error);
    ASSERT_EQ(multiple_items_with_extrema.Max(), univariate_multiple_item_max);
    ASSERT_EQ(multiple_items_with_both.Max(), univariate_multiple_item_max);
}