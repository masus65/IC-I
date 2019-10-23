//#pragma once
#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#ifdef MYLIBRARY_EXPORTS
#define API_MYLIBRARY_LIBRARY __declspec(dllexport)
#else
#define API_MYLIBRARY_LIBRARY __declspec(dllimport)
#endif // MYLIBRARY_EXPORTS

class API_MYLIBRARY_LIBRARY MyLibrary {
private:

public:
	void SayHello() const;
	void SayGoodbay() const;


};











#endif // !MY_LIBRARY_H
