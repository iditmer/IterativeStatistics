#ifndef ITERATIVESTATISTICS_UNIVARIATESAMPLE_H
#define ITERATIVESTATISTICS_UNIVARIATESAMPLE_H

class UnivariateSample
{
private:
	unsigned int count;

public:
	UnivariateSample(bool track_extrema, bool track_variance);
	unsigned int Count() const { return count; }
};

#endif // ITERATIVESTATISTICS_UNIVARIATESAMPLE_H