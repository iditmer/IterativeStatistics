#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <vector>

class MultivariateSample
{
private:

	unsigned int count;

public:

	MultivariateSample() { count = 0; }
	void Update(std::vector<double> vec) { count++; }
	unsigned int Count() const { return count; }

};

#endif // ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H