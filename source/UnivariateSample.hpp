#ifndef ITERATIVESTATISTICS_UNIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_UNIVARIATESAMPLE_H

class UnivariateSample
{
private:
	unsigned int count;
	double sum_x;

public:
	UnivariateSample();
	void Update(double x);

	double Mean() const;
	unsigned int Count() const { return count; }
};

#endif // ITERATIVESTATISTICS_UNIVARIATESAMPLE_H