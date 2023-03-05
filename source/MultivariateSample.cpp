#include "MultivariateSample.hpp"
#include <string>

MultivariateSample::MultivariateSample(int num_dimensions, bool track_variance)
{
	track_var = track_variance;

	dimensionality = num_dimensions;
	count = 0;
	sum_x = std::vector<double>(dimensionality);
	cross_products = std::vector<double>(dimensionality * dimensionality);
}

void MultivariateSample::Update(std::vector<double> vec)
{
	count++;
	for (int i = 0; i < dimensionality; i++) {
		sum_x[i] += vec[i];
	}

	for (int i = 0; i < dimensionality; i++) {
		for (int j = 0; j < dimensionality; j++) {
			cross_products[i * dimensionality + j] += vec[i] * vec[j];
		}
	}
}

std::vector<double> MultivariateSample::Mean() const
{
	if (count < 1) throw std::logic_error("No mean exists for sample of 0 elements.");

	auto mean = std::vector<double>(dimensionality);
	for (int i = 0; i < dimensionality; i++) {
		mean[i] += sum_x[i] / count;
	}
	return mean;
}

double MultivariateSample::Covariance(int row, int column) const
{
	if (!track_var) throw std::logic_error("Covariance not tracked for this sample.");
	else if (row < 0 || row >= dimensionality) throw std::out_of_range("Invalid covariance row index: " + std::to_string(row));
	else if (column < 0 || column >= dimensionality) throw std::out_of_range("Invalid covariance column index: " + std::to_string(column));
	else if (count == 0) throw std::logic_error("Covariance cannot be computed for collection of 0 elements.");
	else if (count == 1) return 0.0;
	else {
		return (1.0 / (count - 1)) * (cross_products[row * dimensionality + column] -
			(1.0 / count) * sum_x[row] * sum_x[column]);
	}
}