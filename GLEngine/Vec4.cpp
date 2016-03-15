#include "Vec4.hpp"

// Constructs object with values assigned to given Matrixf object.
gle::Vec4::Vec4(Matrixf vals)
	: Vec(COMPONENTS, vals)
{
}

// Constructs object with all values assigned to 0.
gle::Vec4::Vec4() 
	: Vec4(0.0f, 0.0f, 0.0f, 0.0f)
{
}

// Constructs object with values assigned to given values.
gle::Vec4::Vec4(const float x, const float y, const float z, const float w)
	: Vec(COMPONENTS)
{
	float vals[] = {x, y, z, w};

	values.Assign(vals);
}

gle::Vec4::~Vec4()
{
}
