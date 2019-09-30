#pragma once
#ifndef ALLOCATION_MEMORY_H
#define ALLOCATION_MEMORY_H

#include <iostream>

namespace AllocationMemory {
	class Point
	{
	public:
		int X;
		int Y;
		Point() {};

		Point(int aX, int aY) : X(aX), Y(aY)
		{
			std::cout << "Call parametric constructor" << std::endl;
		}

		Point(const Point& aSource) : Point(aSource.X, aSource.Y)
		{
			std::cout << "Call copy constructor" << std::endl;
		}
	};


	int& PrintPoint(const Point& aPoint)
	{
		std::cout << aPoint.X << " " << aPoint.Y << "\n";
		int i = 3;
		return i;

	}

	void Sample02()
	{
		int* temp01 = new int();
		Point* point01 = new Point(1, 2); //dynamicky
		std::cout << "address: " << point01 << std::endl;
		const int& i = PrintPoint(*point01);
		Point point02 = Point(2, 2);
		std::cout << "address: " << &point02 << std::endl;
		PrintPoint(point02);

		const Point& point04 = point02;
		//point04 = *point01;

		Point* point03 = new Point[3]();

		delete[] point03;
		delete temp01;
		delete point01;
		//delete point02;

	}

	void Foo(int aNumber)
	{
		return aNumber * aNumber;
	}

}

#endif // !ALLOCATION_MEMORY_H