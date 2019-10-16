#include <time.h>
#include<iostream>
#include "Hra.h"
#include "StatickyObjekt.h"



int main() {


	Game game;
	time_t startTime = time(nullptr);
	for (int idx = 0; idx < 1000; idx++)
	{
		Objekt* objekt;
		if (rand() % 3 == 0) {
			PohyblivyObjekt* pohyblivyObjekt = new PohyblivyObjekt(idx);
			pohyblivyObjekt->SetX(rand() % 100 + 50);
			pohyblivyObjekt->SetY(rand() % 100 + 50);
			objekt = new PohyblivyObjekt(idx);
		}
		else
		{
			objekt = new StaticObjekt(idx, BarrierType::Rock);
		}
		game.InsertObject(objekt);
	}
	time_t endTime = time(nullptr);
	/*char* startBuffer = new char[20];
	char* endBuffer = new char[20];
	ctime_s(startBuffer, 20, &startTime);
	ctime_s(endBuffer, 20, &endTime);*/
	std::cout << "StartTime: " << startBuffer << std::endl
		<< "EndTime: " << endBuffer << std::endl;
	return 0;

}