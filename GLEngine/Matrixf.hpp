#pragma once
#include <vector>

class Matrixf
{
private:
	const unsigned int ROWS;
	const unsigned int COLS;
	const unsigned long MAX;
	bool transposed;
	std::vector<float> values;

	Matrixf(unsigned int, unsigned int, unsigned long);

public:
	Matrixf(unsigned int, unsigned int);
	Matrixf(unsigned int, unsigned int, std::vector<float>);
	~Matrixf();
	void Transpose();

	inline const unsigned int Rows() const { return ROWS; }
	inline const unsigned int Columns() const { return COLS; }
	inline const unsigned long MaxElements() const { return ROWS * COLS; }
	inline const std::vector<float> Values_as_Vector() const { return values; }
	inline const float* Values_as_Ptr() const { return values.data(); }
	
	Matrixf operator+(const Matrixf&) const;
	Matrixf operator-(const Matrixf&) const;
};

