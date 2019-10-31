//#pragma once
#ifndef TEMPLATE_SAMPLE_H
#define TEMPLATE_SAMPLE_H

struct IntPoint{
	int X;
	int Y;
};

IntPoint operator+(const IntPoint& aFirst, const IntPoint& aSecond) {
	//return IntPoint{ aFirst.X + aSecond.X, aFirst.Y + aSecond.Y }; // kratsi zapis 
	IntPoint result;
	result.X = aFirst.X + aSecond.X;
	result.Y = aFirst.Y + aSecond.Y;
	return result;
}

//struct RealPoint {
//	double X;
//	double Y;
//};


template <typename T>
Point<T> operator+(const Point<T>& aFirst, const Point<int>& aSecond) {
	return Point<int>{ aFirst.X + aSecond.X, aFirst.Y + aSecond.Y }; // kratsi zapis 
	IntPoint result;
	result.X = aFirst.X + aSecond.X;
	result.Y = aFirst.Y + aSecond.Y;
	//return result;
}

//template<class T> //starsi
template<typename T> // novejsi prace s jmenama
struct Point{
	T X;
	T Y;
};

template<typename T>
T appendFunction(const T& aWhere, const T& aWhat) {
	return aWhere + aWhat;

}

template <typename TKey, typename TValue = std::string>
struct Pair
{
	TKey Key;
	TValue Value;

};

template <typename T>
class Tree
{
public:


private:


};


#endif // !TEMPLATE_SAMPLE_H

