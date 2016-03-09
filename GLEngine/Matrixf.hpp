#pragma once
#include <vector>

class Matrixf
{
private:
	unsigned int rows;
	unsigned int columns;
	unsigned long maxValues;
	std::vector<float> values;

	void Init(unsigned int, unsigned int);

public:
	Matrixf(unsigned int, unsigned int);
	Matrixf(unsigned int, unsigned int, std::vector<float>);
	~Matrixf();
	Matrixf operator+(const Matrixf&) const;
	Matrixf operator-(const Matrixf&) const;
};

