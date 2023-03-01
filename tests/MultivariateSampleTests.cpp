
#include <gtest/gtest.h>
#include "MultivariateSample.hpp"

class MultivariateSampleTest : public ::testing::Test {

protected:

    MultivariateSample no_items{ 2 };
    MultivariateSample single_item{ 4 };
    MultivariateSample multiple_items{ 7 };

    const std::vector<double> single_item_value = { 1.0, 1.4142135623730951, 1.7320508075688772, 2.0 };
    const std::vector<std::vector<double>> multiple_item_values = {
        std::vector<double>{ 20027.01592, -2945.66691, 13911.23004, 6468.60638, 19643.12585, 38995.19046, 22905.31406 },
        std::vector<double>{ 12858.62301, 35736.50499, 16874.51207, 3143.99859, 7371.40132, 599.55912, 503.76013 },
        std::vector<double>{ 2143.42312, 35517.27960, 11557.36066, 10815.50405, 8585.52034, 11631.98036, 430.30082 },
        std::vector<double>{ 5269.60649, 19040.21184, 16634.52967, -4319.32276, 2967.93167, 790.54502, 6026.82548 },
        std::vector<double>{ 28387.87177, 5462.17156, 21255.73842, 26952.00282, 16325.75082, 4869.15072, 15873.07064 },
        std::vector<double>{ 4612.75794, 13902.40979, 22442.31757, 32337.00917, 6101.15367, 17474.92686, 11515.65426 },
        std::vector<double>{ 7680.57772, 18179.81837, 9464.43818, 1264.15397, 12725.28810, 932.80190, 2802.39486 },
        std::vector<double>{ 3292.01772, 24356.15412, 17443.65240, 35117.32694, 32047.95082, 515.41699, 5971.89982 },
        std::vector<double>{ 10753.38526, 32954.66416, 12510.59954, 8603.98200, -908.60839, 1801.29509, 6302.65020 },
        std::vector<double>{ 37143.69222, 3598.43950, 3417.41060, 10847.68780, 27994.48180, 16415.18956, -2547.44564 },
        std::vector<double>{ -2287.84725, 5154.98904, 22109.26136, 2311.44948, -1530.44338, -5662.93012, 4215.25605 },
        std::vector<double>{ -7399.18339, 46371.60782, 6258.45377, 16961.25734, -399.69258, 592.59289, -1523.98554 },
        std::vector<double>{ 1305.69757, 2238.99594, 31148.77500, 708.29287, 19020.79208, 1607.40399, 35802.11660 },
        std::vector<double>{ -7597.83740, 3318.67837, -5342.75573, 19330.12933, -252.65038, -1473.70540, 22583.54484 },
        std::vector<double>{ 6744.54118, 10495.88679, -6734.11654, 4714.26067, 83.11458, 29964.70112, 9085.12098 },
        std::vector<double>{ 25676.22743, 4874.88104, 1717.71872, 11608.06648, 9745.34185, 2031.08868, 22686.82154 },
        std::vector<double>{ 4614.73626, 12149.65429, -4822.82978, 4325.72224, 23366.98499, 37568.97545, 43881.69213 },
        std::vector<double>{ -3069.70303, 1347.78654, 22965.78622, 10723.95034, 17067.90375, 12136.15683, 6112.24397 },
        std::vector<double>{ 25733.42847, 87.88155, -725.92951, 725.60531, 2243.10071, 1697.63569, 3719.44876 },
        std::vector<double>{ -2393.16677, 21249.79082, 809.01870, 15030.30664, 5739.72094, 14689.24189, 8996.12826 },
        std::vector<double>{ 24712.86217, 7640.57784, 27630.69790, 16408.42324, 12613.15297, 2587.72593, 16380.48641 }
    };

    void SetUp() override {
        single_item.Update(single_item_value);
        
        for (auto& row : multiple_item_values) {
            multiple_items.Update(row);
        }
    }
};

TEST_F(MultivariateSampleTest, Count) {
    ASSERT_EQ(no_items.Count(), 0);
    ASSERT_EQ(single_item.Count(), 1);
    ASSERT_EQ(multiple_items.Count(), multiple_item_values.size());
}

TEST_F(MultivariateSampleTest, Dimensionality) {
    ASSERT_EQ(no_items.Dimensionality(), 2);
    ASSERT_EQ(single_item.Dimensionality(), 4);
    ASSERT_EQ(multiple_items.Dimensionality(), 7);
}