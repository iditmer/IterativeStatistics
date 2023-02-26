
#include "UnivariateSample.hpp"

UnivariateSample::UnivariateSample(bool track_variance, bool track_extrema)
{
	sum_x = 0;
	sum_x_squared = 0;
	count = 0;
	track_var = track_variance;
	track_ext = track_extrema;

	if (track_extrema) update = [this](double x) { this->initial_update(x); };
	else if (track_variance) update = [this](double x) { this->update_with_var(x); };
	else update = [this](double x) { this->update_base(x); };
}

void UnivariateSample::initial_update(double x)
{
	update_base(x);
	min = x;
	max = x;

	if (track_var) {
		sum_x_squared += x * x;
		update = [this](double x) { this->update_full(x); };
	}
	else update = [this](double x) { this->update_with_ext(x); };
}

void UnivariateSample::update_base(double x) 
{
	sum_x += x;
	count++;
}

void UnivariateSample::update_with_var(double x)
{
	update_base(x);
	sum_x_squared += x * x;
}

void UnivariateSample::update_with_ext(double x)
{
	update_base(x);
	min = (min < x) ? min : x;
	max = (max > x) ? max : x;
}

void UnivariateSample::update_full(double x)
{
	update_base(x);
	sum_x_squared += x * x;
	min = (min < x) ? min : x;
	max = (max > x) ? max : x;
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

double UnivariateSample::Min() const
{
	if (!track_ext) throw std::logic_error("Cannot report minimum; extrema not tracked for this sample.");
	else if (count == 0) throw std::logic_error("Minimum cannot be reported for a collection of 0 elements.");
	else return min;
}

double UnivariateSample::Max() const
{
	if (!track_ext) throw std::logic_error("Cannot report maximum; extrema not tracked for this sample.");
	else if (count == 0) throw std::logic_error("Maximum cannot be reported for a collection of 0 elements.");
	else return max;
}