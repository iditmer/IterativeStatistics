#ifndef ITERATIVESTATISTICS_UNIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_UNIVARIATESAMPLE_H

class UnivariateSample
{
private:
	unsigned int count;

public:
	UnivariateSample();
	void Update(double x);

	unsigned int Count() const { return count; }
};

#endif // ITERATIVESTATISTICS_UNIVARIATESAMPLE_H