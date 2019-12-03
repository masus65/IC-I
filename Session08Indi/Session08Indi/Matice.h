//#pragma once
#ifndef MATICE_H
#define MATICE_H

#include<iostream>

template <typename T>

class Matice {
public:
	Matice(int radky, int sloupce);
	Matice(const Matice<T>& m);
	~Matice();
	void Nastav(int radek, int sloupec, T data);
	void NastavZ(T* pole);
	T& get(int radek, int sloupec);
	const T& get(int radek, int sloupec) const;

	template <typename R>
	Matice<R> Pretypuj();

	Matice<T> Transpozice() const;
	Matice<T> Soucin(const Matice& m) const;
	Matice<T> Soucin(T skalar);
	Matice<T> Soucet(const Matice& m) const;
	Matice<T> Soucet(T skalar);

	bool JeShodna(const Matice& m);

	void vypis() const;

private:
	T** _data;
	int _radky;
	int _sloupce;
};

#endif // !MATICE_H

template<typename T>
inline Matice<T>::Matice(int radky, int sloupce)
{
	_radky = radky;
	_sloupce = sloupce;
	_data = new T *[_radky];

	for (size_t i = 0; i < _radky; i++)
	{
		_data[i] = new T[_sloupce]{ 0 };
	}
}

template<typename T>
inline Matice<T>::Matice(const Matice<T>& m)
{
	_radky = m._radky;
	_sloupce = m._sloupce;
	_data = new T *[_radky];

	for (size_t i = 0; i < _radky; i++)
	{
		_data[i] = new T[m._sloupce];
		for (size_t j = 0; j < _sloupce; j++)
		{
			_data[i][j] = m._data[i][j];
		}
	}
}

template<typename T>
inline Matice<T>::~Matice()
{
	for (size_t i = 0; i < _radky; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}

template<typename T>
inline void Matice<T>::Nastav(int radek, int sloupec, T data)
{
	if (radek > _radky || sloupec > _sloupce || radek < 0 || sloupec < 0)
	{
		throw std::invalid_argument("The entered index is not valid.");
	}
	_data[radek][sloupec] = data;
}

template<typename T>
inline void Matice<T>::NastavZ(T* pole)
{
	for (size_t i = 0; i < _radky; i++)
	{
		for (size_t j = 0; j < _sloupce; j++)
		{
			_data[i][j] = pole[(i * this->_sloupce) + j];
		}
	}
}

template<typename T>
inline T& Matice<T>::get(int radek, int sloupec)
{
	if (radek > _radky || sloupec > _sloupce || radek < 0 || sloupec < 0)
	{
		throw std::invalid_argument("The entered index is not valid");
	}
	return _data[radek][sloupec];
}

template<typename T>
inline const T& Matice<T>::get(int radek, int sloupec) const
{
	if (radek > _radky || sloupec > _sloupce || radek < 0 || sloupec < 0)
	{
		throw std::invalid_argument("The entered index is not valid");
	}
	return _data[radek][sloupec];
}

template<typename T>
inline Matice<T> Matice<T>::Transpozice() const
{
	Matice<T> transponded{ _sloupce, _radky };
	for (size_t i = 0; i < _radky; i++)
	{
		for (size_t j = 0; j < _sloupce; j++)
		{
			transponded._data[i][j] = _data[j][i];
		}
	}
	return transponded;
}

template<typename T>
inline Matice<T> Matice<T>::Soucin(const Matice& m) const
{
	if (_sloupce == m._radky)
	{
		Matice<T> newMatrix{ _radky, _sloupce };
		T sum = 0;
		for (size_t i = 0; i < _radky; i++)
		{
			for (size_t j = 0; j < m._sloupce; j++)
			{
				for (size_t z = 0; z < m._radky; z++)
				{
					sum = sum + _data[i][z] * m._data[z][j];
				}
				newMatrix._data[i][j] = sum;
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
inline Matice<T> Matice<T>::Soucin(T skalar)
{
	if constexpr (std::is_arithmetic_v<skalar>)
	{
		Matice<T> newMatrix{ _radky, _sloupce };
		for (size_t i = 0; i < _radky; i++)
		{
			for (size_t j = 0; j < _sloupce; j++)
			{
				newMatrix._data[i][j] = skalar * newMatrix._data[i][j];
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
	if (_radky == m._radky && _sloupce == m._sloupce)
	{
		Matice<T> newMatrix{ _radky, _sloupce };
		for (size_t i = 0; i < _radky; i++)
		{
			for (size_t j = 0; j < _sloupce; j++)
			{
				newMatrix._data[i][j] = _data[i][j] + m._data[i][j];
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
inline Matice<T> Matice<T>::Soucet(T skalar)
{
	if constexpr (std::is_arithmetic_v<skalar>)
	{
		Matice<T> newMatrix{ _radky, _sloupce };
		for (size_t i = 0; i < _radky; i++)
		{
			for (size_t j = 0; j < _sloupce; j++)
			{
				newMatrix._data[i][j] = newMatrix._data[i][j] + skalar;
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
	if (m._radky == _radky && m._sloupce == _sloupce)
	{
		for (size_t i = 0; i < _radky; i++)
		{
			for (size_t j = 0; j < _sloupce; j++)
			{
				if (_data[i][j] != m._data[i][j])
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
inline void Matice<T>::vypis() const
{
	for (size_t i = 0; i < _radky; i++)
	{
		for (size_t j = 0; j < _sloupce; j++)
		{
			std::cout << _data[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
inline Matice<R> Matice<T>::Pretypuj()
{
	Matice<R> newMatrix{ _radky, _sloupce };
	for (size_t i = 0; i < _radky; i++)
	{
		for (size_t j = 0; j < _sloupce; j++)
		{
			newMatrix.Nastav(i, j, static_cast<R>(get(i, j)));
		}
	}
	return newMatrix;
}