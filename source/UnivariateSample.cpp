
#include "UnivariateSample.hpp"

UnivariateSample::UnivariateSample(bool track_variance, bool track_extrema)
{
	sum_x = 0;
	sum_x_squared = 0;
	count = 0;
	track_var = track_variance;

	if (track_variance) update = [this](double x) { this->update_with_var(x); };
	else update = [this](double x) { this->update_base(x); };
}

void UnivariateSample::update_base(double x) 
{
	sum_x += x;
	count++;
}

void UnivariateSample::update_with_var(double x)
{
	sum_x += x;
	sum_x_squared += x * x;
	count++;
}

double UnivariateSample::Mean() const
{
	if (count < 1) throw std::logic_error("No mean exists for sample of 0 elements.");
	return sum_x / count;
}

double UnivariateSample::Variance() const
{
	if (!track_var) throw std::logic_error("Variance not tracked for this sample.");
	else if (count == 0) throw std::logic_error("Variance cannot be computed from a collection of 0 elements.");
	else if (count == 1) return 0.0;
	else return (1.0 / (count - 1)) * (sum_x_squared - (1.0 / count) * sum_x * sum_x);
}

double UnivariateSample::StandardDeviation() const
{
	if (!track_var) throw std::logic_error("Variance not tracked for this sample.");
	else if (count == 0) throw std::logic_error("Standard deviation cannot be computed from a collection of 0 elements.");
	else if (count == 1) return 0.0;
	else return sqrt(Variance());
}
