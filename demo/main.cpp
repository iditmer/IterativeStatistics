#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "UnivariateSample.hpp"

void report_sample(UnivariateSample sample) {

	std::cout << "\nSample Mean:\t" << std::setprecision(3) << sample.Mean() << std::endl;
	std::cout << "Sample Std Dev:\t" << sample.StandardDeviation() << std::endl;

	std::cout << "\nSample Minimum:\t" << sample.Min() << std::endl;
	std::cout << "Minimum is " << (sample.Mean() - sample.Min()) / sample.StandardDeviation();
	std:: cout << " standard deviations from mean." << std::endl;
	
	std::cout << "\nSample Maximum:\t" << sample.Max() << std::endl;
	std::cout << "Maximum is " << (sample.Max() - sample.Mean()) / sample.StandardDeviation();
	std::cout << " standard deviations from mean." << std::endl;
}

int main() {

	const std::vector<int> number_observations = { 100, 500, 1000, 5000 };
	const double distribution_mean = 57.5;
	const double distribution_std = 18.2;

	std::cout << "Distribution Parameters\nMean:\t" << distribution_mean << std::endl;
	std::cout << "Std Dev:\t" << distribution_std << std::endl;

	std::default_random_engine gen;
	std::normal_distribution<double> normal_dist(distribution_mean, distribution_std);

	for (int n : number_observations) {

		UnivariateSample sample_stats{ true,true };
		for (int i = 0; i < n; i++) {
			sample_stats.Update(normal_dist(gen));
		}

		std::cout << "\nAfter " << n << " observations:" << std::endl;
		report_sample(sample_stats);
		std::cout << "\n\n";
	}

	return 0;
}