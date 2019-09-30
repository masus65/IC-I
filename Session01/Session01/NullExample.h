#pragma once

#include <iostream>
#include "AllocationMemory.h"


void Foo(int i)
{
	std::cout << i << std::endl;
	
}

void Foo(int* i)
{
	//null ukazuje do 0 na pamet 0 - nepovoleny pristup do pameti
	std::cout << i << std::endl;
	int id;
	std::cin >> id;
}

void Sample()
{
	Foo(NULL);
	Foo(nullptr);
}