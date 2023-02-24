
#include "UnivariateSample.hpp"
#include <stdexcept>

UnivariateSample::UnivariateSample()
{
	sum_x = 0;
	count = 0;
}

void UnivariateSample::Update(double x)
{
	sum_x += x;
	count++;
}

double UnivariateSample::Mean() const
{
	if (count < 1) throw std::logic_error("No mean exists for sample of 0 elements.");
	return sum_x / count;
}
