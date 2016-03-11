#include "Matrixf.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

Matrixf::Matrixf(uint rows, uint cols)
	: Matrixf(rows, cols, rows * cols)
{
	values.assign(MAX, 0.0f);
}

Matrixf::Matrixf(uint rows, uint cols, std::vector<float> vals)
	: Matrixf(rows, cols, rows * cols)
{
	values = vals;
}

Matrixf::Matrixf(uint rows, uint cols, float vals[])
	: Matrixf(rows, cols, rows * cols)
{
	values.assign(vals, vals + MAX);
}

Matrixf::Matrixf(uint rows, uint cols, ulong max)
	: ROWS(rows), COLS(cols), MAX(max)
{
}

Matrixf::~Matrixf()
{
}

void Matrixf::Print() const 
{
	for (uint row = 0; row < ROWS; ++row)
	{
		for (uint col = 0; col < COLS; ++col)
		{
			std::cout << At(row, col) << " ";
		}

		std::cout << std::endl;
	}
}

void Matrixf::Transpose()
{
	std::vector<float> transposed;

	for (ulong index = 0; index < MAX; ++index)
	{
		int col = index / ROWS;
		int row = index % ROWS;

		transposed.push_back(At(row, col));
	}

	values = transposed;
	
	auto temp = ROWS;
	ROWS = COLS;
	COLS = temp;
}

float Matrixf::At(uint row, uint col) const
{
	return values.at((row * COLS) + col);
}

Matrixf Matrixf::operator+(const Matrixf& b) const
{
	if (ROWS != b.ROWS && COLS != b.COLS)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	std::vector<float> sums;

	for (ulong i = 0; i < MAX; i++)
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

	for (ulong i = 0; i < MAX; i++)
	{
		diffs.push_back(values[i] - b.values[i]);
	}

	Matrixf result(ROWS, COLS, diffs);

	return result;
}

Matrixf Matrixf::operator*(const Matrixf& b) const
{
	if (COLS != b.ROWS)
	{
		throw std::logic_error("Cannot multiply matricies with the dimensions " + 
			std::to_string(ROWS) + "x" + std::to_string(COLS) + " and " + std::to_string(b.ROWS) + "x" + std::to_string(b.COLS));
	}

	std::vector<float> newValues;

	for (uint aRows = 0; aRows < ROWS; ++aRows)
	{
		for (uint bCols = 0; bCols < b.COLS; ++bCols)
		{
			float sum = 0.0f;

			for (uint common = 0; common < COLS; ++common)
			{
				sum += At(aRows, common) * b.At(common, bCols);
			}

			newValues.push_back(sum);
		}
	}

	Matrixf m(ROWS, b.COLS, newValues);
	return m;
}
