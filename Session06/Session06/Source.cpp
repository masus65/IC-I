#include <iostream>
#include "ExceptionSample.h"
#include "TemplateSample.h"


void TemplateSamples() {
	Point<int> intPoint{1,2};
	int result1 = appendFunction<int>(2, 3);
	double result1 = appendFunction<double>(2.3, 2.6);
	//appendFunction(2, 7.6); // error nerozpozna viz dole
	//appendFunction<double>(2, 7.6);

	std::string a("a"), b("b");
	std::string result4 = appendFunction(a, b);
	IntPoint result5 = appendFunction(IntPoint{ 1,1 }, IntPoint{ 2,2 });
	
	Point<int> point{ 1,1 };
	auto result6 = appendFunction<Point<int>>(Point<int>{1, 1}, Point<int>{1, 1});
	auto result7 = appendFunction<Point<double>>(Point<double>{1, 1}, Point<double>{1, 1});
	Pair<int, int> pair1;
	//Pair<int> pair2;

}

int main(int argc, char** argv) {


	//HandleExceptionFunction();
	TemplateSamples();
	return 0;
}