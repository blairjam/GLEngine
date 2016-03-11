#include "Matrixf.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

// Construct object with all values assigned to 0.
Matrixf::Matrixf(const uint rows, const uint cols)
	: Matrixf(rows, cols, rows * cols)
{
	values.assign(MAX, 0.0f);
}

// Construct object with values assigned to given vector.
Matrixf::Matrixf(const uint rows, const uint cols, const std::vector<float> vals)
	: Matrixf(rows, cols, rows * cols)
{
	Assign(vals);
}

// Construct object with values assigned to given array.
Matrixf::Matrixf(const uint rows, const uint cols, const float vals[])
	: Matrixf(rows, cols, rows * cols)
{
	Assign(vals);
}

// Private constructor that assigns ROWS, COLS, and MAX members.
Matrixf::Matrixf(const uint rows, const uint cols, const ulong max)
	: ROWS(rows), COLS(cols), MAX(max)
{
}

Matrixf::~Matrixf()
{
}

// Assign values to given vector.
void Matrixf::Assign(const std::vector<float> vals)
{
	values = vals;
	values.resize(MAX, 0.0f);
}

// Assign values to given array.
void Matrixf::Assign(const float vals[])
{
	values.clear();
	values.assign(vals, vals + MAX);
}

// Transpose the matrix.
void Matrixf::Transpose()
{
	std::vector<float> transposed;

	// Finds the location of all values in the transposed matrix.
	for (ulong index = 0; index < MAX; ++index)
	{
		// Integer division to find the current column to pull from.
		uint col = index / ROWS;
		// Modulus to find the current row to pull from.
		uint row = index % ROWS;

		// Add the value at the found coord to the new vector.
		transposed.push_back(At(row, col));
	}

	// Re-assign values.
	values = transposed;
	
	// Swap ROWS and COLS.
	uint temp = ROWS;
	ROWS = COLS;
	COLS = temp;
}

// Performs scalar multiplication on the matrix.
void Matrixf::Scale(const float scalar)
{
	// Multiply each value by given scalar.
	for (ulong index = 0; index < MAX; ++index)
	{
		values.at(index) *= scalar;
	}
}

// Prints the matrix out row by row.
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

// Performs matrix addition on two matricies.
Matrixf Matrixf::operator+(const Matrixf& b) const
{
	// Throw logic error if matricies are not the same size.
	if (ROWS != b.ROWS && COLS != b.COLS)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	// Vector to hold sums.
	std::vector<float> sums;

	// Add the corresponding values of each matrix.
	for (ulong i = 0; i < MAX; i++)
	{
		sums.push_back(values[i] + b.values[i]);
	}

	// Create and return new matrix.
	Matrixf result(ROWS, COLS, sums);
	return result;
}

// Performs matrix subtraction on two matricies.
Matrixf Matrixf::operator-(const Matrixf& b) const
{
	// Throw logic error if matricies are not the same size.
	if (ROWS != b.ROWS && COLS != b.COLS)
	{
		throw std::logic_error("Cannot add matricies with different dimensions.");
	}

	// Vector to hold differences.
	std::vector<float> diffs;

	// Subtract the corresponding values of each matrix.
	for (ulong i = 0; i < MAX; i++)
	{
		diffs.push_back(values[i] - b.values[i]);
	}

	// Create and return new matrix.
	Matrixf result(ROWS, COLS, diffs);
	return result;
}

// Performs matrix multiplication on two matricies.
Matrixf Matrixf::operator*(const Matrixf& b) const
{
	// Throws logic error if sizes are now valid for multiplication.
	if (COLS != b.ROWS)
	{
		throw std::logic_error("Cannot multiply matricies with the dimensions " + 
			std::to_string(ROWS) + "x" + std::to_string(COLS) + " and " + std::to_string(b.ROWS) + "x" + std::to_string(b.COLS));
	}

	// Vector to hold multiplied values.
	std::vector<float> newValues;

	// Iterate over the rows of matrix A.
	for (uint aRows = 0; aRows < ROWS; ++aRows)
	{
		// Iterate over the columns of matrix B.
		for (uint bCols = 0; bCols < b.COLS; ++bCols)
		{
			float sum = 0.0f;

			// Iterate over each value of A's row and B's column.
			for (uint common = 0; common < COLS; ++common)
			{
				// Keep a sum of values.
				sum += At(aRows, common) * b.At(common, bCols);
			}

			// Add new value to vector.
			newValues.push_back(sum);
		}
	}

	// Create and return the new matrix.
	Matrixf result(ROWS, b.COLS, newValues);
	return result;
}
