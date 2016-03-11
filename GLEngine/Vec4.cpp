#include "Vec4.hpp"

Vec4::Vec4() : Vec4(0.0f, 0.0f, 0.0f, 0.0f)
{
}

Vec4::Vec4(const float x, const float y, const float z, const float w)
	: values(ROWS, COLS)
{
	float vals[] = {x, y, z, w};

	values.Assign(vals);
}

Vec4::Vec4(Matrixf vals)
	: values(vals)
{
}

Vec4::~Vec4()
{
}

void Vec4::Scale(const float scalar)
{
	values.Scale(scalar);
}

void Vec4::Print() const
{
	values.Print();
}

const float Vec4::GetX() const
{
	return values.At(0, COLS - 1);
}

const float Vec4::GetY() const
{
	return values.At(1, COLS - 1);
}

const float Vec4::GetZ() const
{
	return values.At(2, COLS - 1);
}

const float Vec4::GetW() const
{
	return values.At(3, COLS - 1);
}

Vec4 Vec4::operator+(const Vec4& b) const
{
	Vec4 summed(values + b.values);
	return summed;
}

Vec4 Vec4::operator-(const Vec4& b) const
{
	Vec4 differenced(values - b.values);
	return differenced;
}