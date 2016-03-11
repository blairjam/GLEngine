#pragma once
#include "Matrixf.hpp"
#include <cmath>

class Vec4
{
private:
	typedef unsigned int uint;

	static const uint ROWS = 4u;
	static const uint COLS = 1u;
	Matrixf values;

	Vec4(Matrixf);

public:
	Vec4();
	Vec4(const float, const float, const float, const float);
	~Vec4();

	void Scale(const float);
	void Normalize();
	void Print() const;

	const float Length() const;
	inline const float X() const { return values.At(0, COLS - 1); }
	inline const float Y() const { return values.At(1, COLS - 1); }
	inline const float Z() const { return values.At(2, COLS - 1); }
	inline const float W() const { return values.At(3, COLS - 1); }

	Vec4 operator+(const Vec4&) const;
	Vec4 operator-(const Vec4&) const;
};

