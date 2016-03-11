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

	inline const float GetX() const { return values.At(0, COLS - 1); }
	inline const float GetY() const { return values.At(1, COLS - 1); }
	inline const float GetZ() const { return values.At(2, COLS - 1); }
	inline const float GetW() const { return values.At(3, COLS - 1); }

	Vec4 operator+(const Vec4&) const;
	Vec4 operator-(const Vec4&) const;
};

