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
	bool track_ext;
	double min;

	std::function<void(double)> update;

	void initial_update(double x);
	void update_base(double x);
	void update_with_var(double x);
	void update_with_ext(double x);
	void update_full(double x);

public:

	UnivariateSample(bool track_variance, bool track_extrema);
	void Update(double x){ update(x); }

	double Min() const;
	double Mean() const;
	double Variance() const;
	double StandardDeviation() const;
	unsigned int Count() const { return count; }
};

#endif // ITERATIVESTATISTICS_UNIVARIATESAMPLE_H