
#include <gtest/gtest.h>
#include "UnivariateSample.hpp"

class UnivariateSampleTest : public ::testing::Test {

protected:

    UnivariateSample no_items{ true };
    UnivariateSample single_item{ false };
    UnivariateSample single_item_with_variance{ true };
    UnivariateSample multiple_items{ false };
    UnivariateSample multiple_items_with_variance{ true };
    
    const double single_item_value = 3.1415926535;

    const std::vector<double> multiple_item_values{
        -7258.4216, -6672.0069, -612.7034, -3403.0569, -6951.4455,
        6158.8905, -1234.1749, -6625.8533, 6407.0458, 4574.8612,
        4724.2696, -2387.7143, -2184.6552, -2330.7389, 931.2824,
        -3713.6563, 7305.6153, 1821.3522, -4241.8510, -5070.9812,
        -6047.3554, 1658.9211, -2241.4804, -7381.3727, -7482.0950 
    };

    const double multiple_item_mean = -1690.2929919999997;
    const double multiple_item_variance = 22478445.52748002;
    const double multiple_item_standard_deviation = 4645.35334569727;
    
    void SetUp() override {

        single_item.Update(single_item_value);
        single_item_with_variance.Update(single_item_value);

        for (auto& x : multiple_item_values) {
            multiple_items.Update(x);
            multiple_items_with_variance.Update(x);
        }
    }
};

TEST_F(UnivariateSampleTest, Count) {
    EXPECT_EQ(no_items.Count(), 0);
    EXPECT_EQ(single_item.Count(), 1);
    EXPECT_EQ(single_item_with_variance.Count(), 1);
    EXPECT_EQ(multiple_items.Count(), multiple_item_values.size());
    EXPECT_EQ(multiple_items_with_variance.Count(), multiple_item_values.size());
}

TEST_F(UnivariateSampleTest, Mean) {
    EXPECT_THROW(no_items.Mean(), std::logic_error);
    EXPECT_EQ(single_item.Mean(), single_item_value);
    EXPECT_EQ(single_item_with_variance.Mean(), single_item_value);
    EXPECT_NEAR(multiple_items.Mean(), multiple_item_mean, 1e-12);
    EXPECT_NEAR(multiple_items_with_variance.Mean(), multiple_item_mean, 1e-12);
}

TEST_F(UnivariateSampleTest, Variance) {
    EXPECT_THROW(no_items.Variance(), std::logic_error);
    EXPECT_THROW(single_item.Variance(), std::logic_error);
    EXPECT_EQ(single_item_with_variance.Variance(), 0.0);
    EXPECT_THROW(multiple_items.Variance(), std::logic_error);
    EXPECT_NEAR(multiple_items_with_variance.Variance(), multiple_item_variance, 1e-7);
}

TEST_F(UnivariateSampleTest, StandardDeviation) {
    EXPECT_THROW(no_items.StandardDeviation(), std::logic_error);
    EXPECT_THROW(single_item.StandardDeviation(), std::logic_error);
    EXPECT_EQ(single_item_with_variance.StandardDeviation(), 0.0);
    EXPECT_THROW(multiple_items.StandardDeviation(), std::logic_error);
    EXPECT_NEAR(multiple_items_with_variance.StandardDeviation(), multiple_item_standard_deviation, 1e-11);
}