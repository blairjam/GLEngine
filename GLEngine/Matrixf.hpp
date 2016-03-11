#pragma once
#include <vector>

class Matrixf
{
private:
	typedef unsigned int uint;
	typedef unsigned long ulong;

	uint ROWS;
	uint COLS;
	const ulong MAX;
	std::vector<float> values;

	Matrixf(const uint, const uint, const ulong);

public:
	Matrixf(const uint, const uint);
	Matrixf(const uint, const uint, const std::vector<float>);
	Matrixf(const uint, const uint, const float[]);
	~Matrixf();

	void Assign(const std::vector<float>);
	void Assign(const float[]);
	void Transpose();
	void Scale(const float);
	void Print() const;

	// Return value at given index.
	inline const float At(const uint row, const uint col) const { return values.at((row * COLS) + col); }
	inline const uint Rows() const { return ROWS; }
	inline const uint Columns() const { return COLS; }
	inline const ulong MaxElements() const { return MAX; }
	inline const std::vector<float> Values_as_Vector() const { return values; }
	inline const float* Values_as_Ptr() const { return values.data(); }
	
	Matrixf operator+(const Matrixf&) const;
	Matrixf operator-(const Matrixf&) const;
	Matrixf operator*(const Matrixf&) const;
};


