#include "MultivariateSample.hpp"

MultivariateSample::MultivariateSample(int num_dimensions)
{
	dimensionality = num_dimensions;
	count = 0;
	sum_x = std::vector<double>(dimensionality);
}

void MultivariateSample::Update(std::vector<double> vec)
{
	count++;
	for (int i = 0; i < dimensionality; i++) {
		sum_x[i] += vec[i];
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
