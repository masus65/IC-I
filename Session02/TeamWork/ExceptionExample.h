//#pragma once

#ifndef EXCEPTION_EXAMPLE_H
#define EXCEPTION_EXAMPLE_H

#include <iostream>
#include <exception>

void ExceptionExample01() 
{
	std::cout << "Zadejte delenec: ";
	int delenec;
	std::cin >> delenec;

	std::cout << "Zadejte delitele: ";
	int delitel;
	std::cin >> delitel;

	double result = (double)delenec / delitel;
	std::cout << "vysledek je: " << result << std::endl;

}

void ExceptionExample02()
{
	//sizeof(values) /sizeof(values[0]);
	int values[5];
	int count = sizeof(values) / sizeof(values[0]);
	try
	{
		//values[7] = 1;
	
	for (size_t i = 0; i <= count; i++)
	{
		values[i] = i;
	}
	}
	catch (std::exception& ex)
	{
	std::cout << ex.what() << std::endl;
	}
	catch (...)
	{

	}

}



#endif // EXCEPTION_EXAMPLE_H
