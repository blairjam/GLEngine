#include "Vec4.hpp"

// Constructs object with all values assigned to 0.
Vec4::Vec4() : Vec4(0.0f, 0.0f, 0.0f, 0.0f)
{
}

// Constructs object with values assigned to given values.
Vec4::Vec4(const float x, const float y, const float z, const float w)
	: values(ROWS, COLS)
{
	float vals[] = {x, y, z, w};

	values.Assign(vals);
}

// Constructs object with values assigned to given Matrixf object.
Vec4::Vec4(Matrixf vals)
	: values(vals)
{
}

Vec4::~Vec4()
{
}

// Performs scalar multiplication on the vector.
void Vec4::Scale(const float scalar)
{
	values.Scale(scalar);
}

// Prints out the vector value by value.
void Vec4::Print() const
{
	values.Print();
}

// Performs addition of two vectors.
Vec4 Vec4::operator+(const Vec4& b) const
{
	Vec4 summed(values + b.values);
	return summed;
}

// Performs subtraction of two vectors.
Vec4 Vec4::operator-(const Vec4& b) const
{
	Vec4 differenced(values - b.values);
	return differenced;
}