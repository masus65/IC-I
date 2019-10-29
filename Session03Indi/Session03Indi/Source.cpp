#include <iostream>
#include "StatickyObjekt.h"
#include <typeinfo>
#include "Hra.h"

using namespace std;


int main(int argc, char** argv)
{
	Hra hra{ 6 };

	StatickyObjekt s1{ 0,Skala };
	s1.SetX(1);
	s1.SetY(1);
	hra.vlozObjekt(&s1);

	StatickyObjekt s2{ 1,VelkaRostlina };
	s2.SetX(10);
	s2.SetY(5);
	hra.vlozObjekt(&s2);

	StatickyObjekt s3{ 2,MalaRostlina };
	s3.SetX(6);
	s3.SetY(6);
	hra.vlozObjekt(&s3);

	PohyblivyObjekt p1{};
	p1.SetX(2);
	p1.SetY(2);
	p1.setUhelNatoceni(0);
	hra.vlozObjekt(&p1);

	PohyblivyObjekt p2{};
	p2.SetX(3);
	p2.SetY(5);
	p2.setUhelNatoceni(180);
	hra.vlozObjekt(&p2);

	PohyblivyObjekt p3{};
	p3.SetX(10);
	p3.SetY(10);
	p3.setUhelNatoceni(360);
	hra.vlozObjekt(&p3);

	int* idArray = hra.najdiIdStatickychObjektu(5, 10, 5, 10);
	PohyblivyObjekt** mObjArray1 = hra.najdiPohybliveObjektyVOblasti(5, 10, 5);
	PohyblivyObjekt** mObjArray2 = hra.najdiPohybliveObjektyVOblasti(5, 10, 5, 0, 180);

	delete[] idArray;
	delete[] mObjArray1;
	delete[] mObjArray2;
	/*for (int i = 0; i < std::size(idArray); i++)
	{
		cout << idArray[i] << endl;
	}*/
	/*for (int i = 0; i < hra.getPocetObjektu(); i++)
	{
		cout << hra.objekty[i]->getId ()<< endl;
	}*/
}