#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
struct Exception {
private:
	std::string message;
public:
	Exception(std::string message);
	virtual std::string getMessage();
};

struct NoSuchElementException : Exception {
	NoSuchElementException(std::string message) : Exception(message) {}
};

struct WrongInputException : Exception {
	WrongInputException(std::string message) : Exception(message) {}
};
#endif