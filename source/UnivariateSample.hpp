#ifndef ITERATIVESTATISTICS_UNIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_UNIVARIATESAMPLE_H

#include <functional>
#include <stdexcept>

class UnivariateSample
{
private:

	unsigned int count;
	double sum_x;
	double sum_x_squared;
	bool track_var;

	std::function<void(double)> update;

	void update_base(double x);
	void update_with_var(double x);

public:

	UnivariateSample(bool track_variance);
	void Update(double x){ update(x); }

	double Mean() const;
	double Variance() const;
	double StandardDeviation() const;
	unsigned int Count() const { return count; }
};

#endif // ITERATIVESTATISTICS_UNIVARIATESAMPLE_H