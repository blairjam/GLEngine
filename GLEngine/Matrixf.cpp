#include "Matrixf.hpp"
#include <stdexcept>

Matrixf::Matrixf(unsigned int rows, unsigned int cols)
	: Matrixf(rows, cols, rows * cols)
{
	values.assign(MAX, 0.0f);
}

Matrixf::Matrixf(unsigned int rows, unsigned int cols, std::vector<float> vals)
	: Matrixf(rows, cols, rows * cols)
{
	values = vals;
}

Matrixf::Matrixf(unsigned int rows, unsigned int cols, unsigned long max)
	: ROWS(rows), COLS(cols), MAX(max), transposed(false)
{
}

Matrixf::~Matrixf()
{
}

void Matrixf::Transpose()
{
	transposed = !transposed;
}

Matrixf Matrixf::operator+(const Matrixf& b) const
{
	if (ROWS != b.ROWS && COLS != b.COLS)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	std::vector<float> sums;

	for (unsigned long i = 0; i < MAX; i++)
	{
		sums.push_back(values[i] + b.values[i]);
	}

	Matrixf result(ROWS, COLS, sums);

	return result;
}

Matrixf Matrixf::operator-(const Matrixf& b) const
{
	if (ROWS != b.ROWS && COLS != b.COLS)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	std::vector<float> diffs;

	for (unsigned long i = 0; i < MAX; i++)
	{
		diffs.push_back(values[i] - b.values[i]);
	}

	Matrixf result(ROWS, COLS, diffs);

	return result;
}
