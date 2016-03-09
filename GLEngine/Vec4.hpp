#pragma once
class Vec4
{
private:
	static const unsigned int ELEMENTS = 4u;
	float values[ELEMENTS];

public:
	Vec4();
	Vec4(float, float, float, float);
	~Vec4();
	const float GetX() const;
	const float GetY() const;
	const float GetZ() const;
	const float GetW() const;
	Vec4 operator+(const Vec4&) const;
	Vec4 operator-(const Vec4&) const;
};

