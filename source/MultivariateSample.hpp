#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <functional>
#include <vector>
#include <stdexcept>

class MultivariateSample
{
private:

	int dimensionality;
	unsigned long long count;
	std::vector<double> sum_x;

	bool track_var;
	std::vector<double> cross_products;

	bool track_ext;
	std::vector<double> min;
	std::vector<double> max;

	std::function<void(std::vector<double>)> update;
	void initial_update(std::vector<double> v);
	void update_base(std::vector<double> v);
	void update_with_cov(std::vector<double> v);
	void update_with_ext(std::vector<double> v);
	void update_full(std::vector<double> v);

public:

	MultivariateSample(int num_dimensions, bool track_variance, bool track_extrema);
	void Update(std::vector<double> v) { update(v); }

	unsigned long long Count() const { return count; }
	int Dimensionality() const { return dimensionality; }

	std::vector<double> Mean() const;
	double Covariance(int row, int column) const;

	std::vector<double> Min() const;
	std::vector<double> Max() const;
};

#endif