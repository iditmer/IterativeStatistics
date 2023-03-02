#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <vector>
#include <stdexcept>

class MultivariateSample
{
private:

	unsigned long long count;
	int dimensionality;

	std::vector<double> sum_x;

public:

	MultivariateSample(int num_dimensions);
	void Update(std::vector<double> vec);

	unsigned long long Count() const { return count; }
	int Dimensionality() const { return dimensionality; }

	std::vector<double> Mean() const;
};

#endif // ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H