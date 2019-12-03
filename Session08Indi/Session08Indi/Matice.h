//#pragma once
#ifndef MATICE_H
#define MATICE_H

#include<iostream>

template <typename T>

class Matice {
public:
	Matice(int rowCount, int columnCount);
	Matice(const Matice<T>& m);
	~Matice();
	void Nastav(int row, int column, T value);
	void NastavZ(T* arr);
	T& get(int row, int column);
	const T& get(int row, int column) const;

	template <typename R>
	Matice<R> Pretypuj();

	Matice<T> Transpozice() const;
	Matice<T> Soucin(const Matice& m) const;
	Matice<T> Soucin(T scalar);
	Matice<T> Soucet(const Matice& m) const;
	Matice<T> Soucet(T scalar);

	bool JeShodna(const Matice& m);

	void print() const;

private:
	T** _values;
	int _rowCount;
	int _columnCount;
};

#endif // !MATRIX_H

template<typename T>
inline Matice<T>::Matice(int rowCount, int columnCount)
{
	_rowCount = rowCount;
	_columnCount = columnCount;
	_values = new T *[_rowCount];

	for (size_t i = 0; i < _rowCount; i++)
	{
		_values[i] = new T[_columnCount]{ 0 };
	}
}

template<typename T>
inline Matice<T>::Matice(const Matice<T>& m)
{
	_rowCount = m._rowCount;
	_columnCount = m._columnCount;
	_values = new T *[_rowCount];

	for (size_t i = 0; i < _rowCount; i++)
	{
		_values[i] = new T[m._columnCount];
		for (size_t j = 0; j < _columnCount; j++)
		{
			_values[i][j] = m._values[i][j];
		}
	}
}

template<typename T>
inline Matice<T>::~Matice()
{
	for (size_t i = 0; i < _rowCount; i++)
	{
		delete[] _values[i];
	}
	delete[] _values;
}

template<typename T>
inline void Matice<T>::Nastav(int row, int column, T value)
{
	if (row > _rowCount || column > _columnCount || row < 0 || column < 0)
	{
		throw std::invalid_argument("The entered index is not valid.");
	}
	_values[row][column] = value;
}

template<typename T>
inline void Matice<T>::NastavZ(T* arr)
{
	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _columnCount; j++)
		{
			_values[i][j] = arr[(i * this->_columnCount) + j];
		}
	}
}

template<typename T>
inline T& Matice<T>::get(int row, int column)
{
	if (row > _rowCount || column > _columnCount || row < 0 || column < 0)
	{
		throw std::invalid_argument("The entered index is not valid");
	}
	return _values[row][column];
}

template<typename T>
inline const T& Matice<T>::get(int row, int column) const
{
	if (row > _rowCount || column > _columnCount || row < 0 || column < 0)
	{
		throw std::invalid_argument("The entered index is not valid");
	}
	return _values[row][column];
}

template<typename T>
inline Matice<T> Matice<T>::Transpozice() const
{
	Matice<T> transponded{ _columnCount, _rowCount };
	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _columnCount; j++)
		{
			transponded._values[i][j] = _values[j][i];
		}
	}
	return transponded;
}

template<typename T>
inline Matice<T> Matice<T>::Soucin(const Matice& m) const
{
	if (_columnCount == m._rowCount)
	{
		Matice<T> newMatrix{ _rowCount, _columnCount };
		T sum = 0;
		for (size_t i = 0; i < _rowCount; i++)
		{
			for (size_t j = 0; j < m._columnCount; j++)
			{
				for (size_t z = 0; z < m._rowCount; z++)
				{
					sum = sum + _values[i][z] * m._values[z][j];
				}
				newMatrix._values[i][j] = sum;
				sum = 0;
			}
		}
		return newMatrix;
	}
	else
	{
		throw std::exception("The dimensions of the matrix cannot be used to calculate product.");
	}
}

template<typename T>
inline Matice<T> Matice<T>::Soucin(T scalar)
{
	if constexpr (std::is_arithmetic_v<scalar>)
	{
		Matice<T> newMatrix{ _rowCount, _columnCount };
		for (size_t i = 0; i < _rowCount; i++)
		{
			for (size_t j = 0; j < _columnCount; j++)
			{
				newMatrix._values[i][j] = scalar * newMatrix._values[i][j];
			}
		}
		return newMatrix;
	}
	else
	{
		std::invalid_argument("The inputed parameter was not considered a number value.");
	}
}

template<typename T>
inline Matice<T> Matice<T>::Soucet(const Matice& m) const
{
	if (_rowCount == m._rowCount && _columnCount == m._columnCount)
	{
		Matice<T> newMatrix{ _rowCount, _columnCount };
		for (size_t i = 0; i < _rowCount; i++)
		{
			for (size_t j = 0; j < _columnCount; j++)
			{
				newMatrix._values[i][j] = _values[i][j] + m._values[i][j];
			}
		}
		return newMatrix;
	}
	else
	{
		throw std::invalid_argument("The dimensions of both matrixes are not the same.");
	}
}

template<typename T>
inline Matice<T> Matice<T>::Soucet(T scalar)
{
	if constexpr (std::is_arithmetic_v<scalar>)
	{
		Matice<T> newMatrix{ _rowCount, _columnCount };
		for (size_t i = 0; i < _rowCount; i++)
		{
			for (size_t j = 0; j < _columnCount; j++)
			{
				newMatrix._values[i][j] = newMatrix._values[i][j] + scalar;
			}
		}
		return newMatrix;
	}
	else
	{
		throw std::invalid_argument("The inputed parameter was not considered a number value");
	}
}

template<typename T>
inline bool Matice<T>::JeShodna(const Matice& m)
{
	if (m._rowCount == _rowCount && m._columnCount == _columnCount)
	{
		for (size_t i = 0; i < _rowCount; i++)
		{
			for (size_t j = 0; j < _columnCount; j++)
			{
				if (_values[i][j] != m._values[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		throw std::exception("Dimensions of both matrixes are not the same.");
	}
}

template<typename T>
inline void Matice<T>::print() const
{
	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _columnCount; j++)
		{
			std::cout << _values[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
inline Matice<R> Matice<T>::Pretypuj()
{
	Matice<R> newMatrix{ _rowCount, _columnCount };
	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _columnCount; j++)
		{
			newMatrix.Nastav(i, j, static_cast<R>(get(i, j)));
		}
	}
	return newMatrix;
}