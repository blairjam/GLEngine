#include "Vec.hpp"
#include <vector>
#include <cmath>

gle::Vec::Vec(uint elements, Matrix<float> vals)
	: ELEMENTS(elements), COLS(1u), values(vals)
{
}

gle::Vec::Vec(uint elements)
	:ELEMENTS(elements), COLS(1u), values(ELEMENTS, COLS)
{
}

gle::Vec::~Vec()
{
}

// Performs scalar multiplication on the vector.
void gle::Vec::Scale(const float scalar)
{
	values.Scale(scalar);
}

void gle::Vec::Normalize()
{
	const float length = Length();

	std::vector<float> norms;

	for (uint index = 0; index < ELEMENTS; ++index)
	{
		float value = At(index);

		norms.push_back(value / length);
	}

	values.Assign(norms);
}

// Prints out the vector value by value.
void gle::Vec::Print() const
{
	values.Print();
}

const float gle::Vec::Length() const
{
	float squareSum = 0.0f;

	for (uint index = 0; index < ELEMENTS; ++index)
	{
		float value = At(index);

		squareSum += value * value;
	}

	return std::sqrtf(squareSum);
}

// Performs addition of two vectors.
gle::Vec gle::Vec::operator+(const Vec& b) const
{
	Vec summed(ELEMENTS, values + b.values);
	return summed;
}

// Performs subtraction of two vectors.
gle::Vec gle::Vec::operator-(const Vec& b) const
{
	Vec differenced(ELEMENTS, values - b.values);
	return differenced;
}
