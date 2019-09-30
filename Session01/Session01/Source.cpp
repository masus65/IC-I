#include "NullExample.h"
#include "AllocationMemory.h"
#include <iostream>
//#include "iostream"
namespace AllocationMemory
{
	void Barrr()
	{
		Foo(30);
	}
}

//using namespace AllocationMemory

int main(int argc, char** argv)
{
	AllocationMemory::Barrr();
	Sample();
	AllocationMemory::Sample02();
	AllocationMemory::Foo(3);
	//AllocationMemory::Sample02();



	return 0;
}