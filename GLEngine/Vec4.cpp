#include "Vec4.hpp"

Vec4::Vec4() : Vec4(0.0f, 0.0f, 0.0f, 0.0f)
{
}

Vec4::Vec4(float x, float y, float z, float w)
{
	values[0] = x;
	values[1] = y;
	values[2] = z;
	values[3] = w;
}

Vec4::~Vec4()
{
}

const float Vec4::GetX() const
{
	return values[0];
}

const float Vec4::GetY() const
{
	return values[1];
}

const float Vec4::GetZ() const
{
	return values[2];
}

const float Vec4::GetW() const
{
	return values[3];
}

Vec4 Vec4::operator+(const Vec4& opp) const
{
	float sums[ELEMENTS];

	for (unsigned int i = 0; i < ELEMENTS; i++)
	{
		sums[i] = values[i] + opp.values[i];
	}

	Vec4 summed(sums[0], sums[1], sums[2], sums[3]);

	return summed;
}

Vec4 Vec4::operator-(const Vec4& opp) const
{
	float diffs[ELEMENTS];

	for (unsigned int i = 0; i < ELEMENTS; i++)
	{
		diffs[i] = values[i] - opp.values[i];
	}

	Vec4 difference(diffs[0], diffs[1], diffs[2], diffs[3]);

	return difference;
}