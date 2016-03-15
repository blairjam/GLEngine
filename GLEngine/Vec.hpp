#pragma once
#include "Matrixf.hpp"

namespace gle
{
	class Vec
	{
	protected:
		typedef unsigned int uint;

		const uint ELEMENTS;
		const uint COLS;
		Matrixf values;

		Vec(uint, Matrixf);

	public:
		Vec(uint);
		virtual ~Vec();

		void Scale(const float);
		void Normalize();
		void Print() const;

		const float Length() const;
		inline const float At(uint index) const { return values.At(index, 0); }

		Vec operator+(const Vec&) const;
		Vec operator-(const Vec&) const;
	};
}


