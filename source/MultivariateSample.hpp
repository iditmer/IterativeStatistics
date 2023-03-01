#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <vector>

class MultivariateSample
{
private:

	unsigned long long count;

public:

	MultivariateSample() { count = 0; }
	void Update(std::vector<double> vec) { count++; }
	unsigned long long Count() const { return count; }

};

#endif // ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H