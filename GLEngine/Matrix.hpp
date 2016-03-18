#pragma once
#include <vector>

namespace gle
{
	template <class T> class Matrix
	{
	private:
		typedef unsigned int uint;
		typedef unsigned long ulong;

		uint ROWS;
		uint COLS;
		const ulong MAX;
		std::vector<T> values;

		Matrix(const uint, const uint, const ulong);

	public:
		Matrix(const uint, const uint);
		Matrix(const uint, const uint, const std::vector<T>);
		Matrix(const uint, const uint, const T[]);
		~Matrix();

		void Assign(const std::vector<T>);
		void Assign(const T[]);
		void Transpose();
		void Scale(const T);
		void Print() const;

		// Return value at given index.
		inline const T At(const uint row, const uint col) const { return values.at((row * COLS) + col); }
		inline const uint Rows() const { return ROWS; }
		inline const uint Columns() const { return COLS; }
		inline const ulong MaxElements() const { return MAX; }
		inline const std::vector<T> Values_as_Vector() const { return values; }
		inline const T* Values_as_Ptr() const { return values.data(); }

		Matrix<T> operator+(const Matrix<T>&) const;
		Matrix<T> operator-(const Matrix<T>&) const;
		Matrix<T> operator*(const Matrix<T>&) const;
	};
}
