#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <vector>
#include <stdexcept>

class MultivariateSample
{
private:

	unsigned long long count;
	int dimensionality;

	bool track_var;

	std::vector<double> sum_x;

public:

	MultivariateSample(int num_dimensions, bool track_variance);
	void Update(std::vector<double> vec);

	unsigned long long Count() const { return count; }
	int Dimensionality() const { return dimensionality; }

	std::vector<double> Mean() const;
	double Covariance(int row, int column) const;
};

#endif // ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H