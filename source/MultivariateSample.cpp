#include "MultivariateSample.hpp"
#include <string>

MultivariateSample::MultivariateSample(int num_dimensions, bool track_variance)
{
	track_var = track_variance;

	dimensionality = num_dimensions;
	count = 0;
	sum_x = std::vector<double>(dimensionality);
	if (track_variance) {
		cross_products = std::vector<double>(dimensionality * (dimensionality + 1) / 2);
	}
}

void MultivariateSample::Update(std::vector<double> vec)
{
	count++;
	for (int i = 0; i < dimensionality; i++) {
		sum_x[i] += vec[i];
	}

	if (track_var) {

		for (int i = 0; i < dimensionality; i++) {
			for (int j = i; j < dimensionality; j++) {
				cross_products[j + i * dimensionality - i * (i + 1) / 2] += vec[i] * vec[j];
			}
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
		int max = (row > column) ? row : column;
		int min = (row < column) ? row : column;
		return (1.0 / (count - 1)) * (cross_products[max + min * dimensionality - min * (min + 1) / 2] -
			(1.0 / count) * sum_x[row] * sum_x[column]);
	}
}