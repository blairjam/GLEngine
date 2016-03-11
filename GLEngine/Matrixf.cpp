#include "Matrixf.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

Matrixf::Matrixf(const uint rows, const uint cols)
	: Matrixf(rows, cols, rows * cols)
{
	values.assign(MAX, 0.0f);
}

Matrixf::Matrixf(const uint rows, const uint cols, const std::vector<float> vals)
	: Matrixf(rows, cols, rows * cols)
{
	Assign(vals);
}

Matrixf::Matrixf(const uint rows, const uint cols, const float vals[])
	: Matrixf(rows, cols, rows * cols)
{
	Assign(vals);
}

Matrixf::Matrixf(const uint rows, const uint cols, const ulong max)
	: ROWS(rows), COLS(cols), MAX(max)
{
}

Matrixf::~Matrixf()
{
}

void Matrixf::Assign(const std::vector<float> vals)
{
	values = vals;
}

void Matrixf::Assign(const float vals[])
{
	values.clear();
	values.assign(vals, vals + MAX);
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

void Matrixf::Scale(const float scalar)
{
	for (ulong index = 0; index < MAX; ++index)
	{
		values.at(index) *= scalar;
	}
}

float Matrixf::At(const uint row, const uint col) const
{
	return values.at((row * COLS) + col);
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
