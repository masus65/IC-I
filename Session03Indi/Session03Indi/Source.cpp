#include <iostream>
#include "StatickyObjekt.h"
#include <typeinfo>
#include "Hra.h"

using namespace std;

int main()
{
	Hra hra{ };

	StatickyObjekt s1{ 0, TypPrekazky::Skala };
	s1.SetX(10);
	s1.SetY(5);
	hra.vlozObjekt(&s1);

}