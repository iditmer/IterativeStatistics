#ifndef ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_MULTIVARIATESAMPLE_H

#include <functional>
#include <vector>
#include <stdexcept>

class MultivariateSample
{
private:

	unsigned long long count;
	int dimensionality;
	bool track_var;

	std::function<void(std::vector<double>)> update;
	void update_base(std::vector<double> v);
	void update_with_cov(std::vector<double> v);

	std::vector<double> sum_x;
	std::vector<double> cross_products;

public:

	MultivariateSample(int num_dimensions, bool track_variance);
	void Update(std::vector<double> v) { update(v); }

	unsigned long long Count() const { return count; }
	int Dimensionality() const { return dimensionality; }

	std::vector<double> Mean() const;
	double Covariance(int row, int column) const;
};

#endif