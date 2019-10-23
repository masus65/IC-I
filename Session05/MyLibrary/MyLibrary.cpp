#include "MyLibrary.h"
#include <iostream>




void MyLibrary::SayHello() const{
	std::cout << "Hello from MyLibrary!" << std::endl;

}

void MyLibrary::SayGoodbay() const{

	std::cout << "Goodbye from MyLibrary!" << std::endl;
}
