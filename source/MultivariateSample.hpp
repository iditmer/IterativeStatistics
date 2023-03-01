#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <vector>

class MultivariateSample
{
private:

	unsigned long long count;
	int dimensionality;

public:

	MultivariateSample(int num_dimensions) { count = 0; dimensionality = num_dimensions; }
	void Update(std::vector<double> vec) { count++; }
	unsigned long long Count() const { return count; }
	int Dimensionality() const { return dimensionality; }

};

#endif // ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H