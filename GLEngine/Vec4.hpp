#pragma once
#include "Matrixf.hpp"

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
	void Print() const;

	const float GetX() const;
	const float GetY() const;
	const float GetZ() const;
	const float GetW() const;

	Vec4 operator+(const Vec4&) const;
	Vec4 operator-(const Vec4&) const;
};

