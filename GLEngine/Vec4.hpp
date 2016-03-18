#pragma once
#include "Vec.hpp"
#include "Matrix.hpp"

namespace gle
{
	class Vec4 : public Vec
	{
	private:
		Vec4(Matrix<float>);

	public:
		static const uint COMPONENTS = 4u;

		Vec4();
		Vec4(const float, const float, const float, const float);
		~Vec4();

		inline const float X() const { return values.At(0, 0); }
		inline const float Y() const { return values.At(1, 0); }
		inline const float Z() const { return values.At(2, 0); }
		inline const float W() const { return values.At(3, 0); }
	};
}
