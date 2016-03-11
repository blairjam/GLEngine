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

	Matrixf(uint, uint, ulong);

public:
	Matrixf(uint, uint);
	Matrixf(uint, uint, std::vector<float>);
	Matrixf(uint, uint, float[]);
	~Matrixf();
	void Print() const;
	void Transpose();
	float At(uint, uint) const;

	inline const uint Rows() const { return ROWS; }
	inline const uint Columns() const { return COLS; }
	inline const ulong MaxElements() const { return MAX; }
	inline const std::vector<float> Values_as_Vector() const { return values; }
	inline const float* Values_as_Ptr() const { return values.data(); }
	
	Matrixf operator+(const Matrixf&) const;
	Matrixf operator-(const Matrixf&) const;
	Matrixf operator*(const Matrixf&) const;
};


