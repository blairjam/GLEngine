#include "Matrixf.hpp"
#include <exception>

Matrixf::Matrixf(unsigned int rows_, unsigned int columns_)
{
	Init(rows_, columns_);

	values.assign(maxValues, 0.0f);
}

Matrixf::Matrixf(unsigned int rows_, unsigned int columns_, std::vector<float> values_)
{
	Init(rows_, columns_);

	values = values_;
	values.resize(maxValues);
}

Matrixf::~Matrixf()
{
}

void Matrixf::Init(unsigned int rows_, unsigned int columns_)
{
	rows = rows_;
	columns = columns_;

	maxValues = rows * columns;
}

Matrixf Matrixf::operator+(const Matrixf& b) const
{
	if (rows != b.rows && columns != b.columns)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	std::vector<float> sums;

	for (unsigned long i = 0; i < maxValues; i++)
	{
		sums.push_back(values[i] + b.values[i]);
	}

	Matrixf result(rows, columns, sums);

	return result;
}

Matrixf Matrixf::operator-(const Matrixf& b) const
{
	if (rows != b.rows && columns != b.columns)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	std::vector<float> diffs;

	for (unsigned long i = 0; i < maxValues; i++)
	{
		diffs.push_back(values[i] - b.values[i]);
	}

	Matrixf result(rows, columns, diffs);

	return result;
}
