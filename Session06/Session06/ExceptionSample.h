//#pragma once
#ifndef EXCEPTION_SAMPLE_H
#define EXPECPION_SAMPLE_H
#include <stdexcept>
#include <iostream>


void ThowExceptionFunction() {
	throw std::exception("Generic exception");
	//throw new std::exception("Generic exception");
}

void HandleExceptionFunction() {
	try {
		ThowExceptionFunction();
	}
	//catch (std::exception e) { //nejpouzivanejsi
	//catch (std::exception& e){
	catch (const std::exception& e){ //good
		std::cerr << e.what() << std::endl;
		//throw e;
		throw;
	}
	catch (std::exception* e) {
		std::cerr << e->what() << std::endl;
		delete e;
	}
}


#endif // !EXCEPTION_SAMPLE_H

