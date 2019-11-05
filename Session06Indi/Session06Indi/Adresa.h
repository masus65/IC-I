#pragma once
#ifndef ADRESA_H
#define ADRESA_H
#include <string>
#include <iostream>

// Vytvoøte strukturu Adresa (string _ulice, string _mesto, int _psc).
class Adresa{
private:
	std::string _ulice;
	std::string _mesto;
	int _psc;

public:
	Adresa(std::string aUlice, std::string aMesto, int aPsc);
	Adresa();
	friend std::ostream& operator<<(std::ostream& os, const Adresa& dt);
	friend std::istream& operator>>(std::istream& is, Adresa& dt);
};


#endif // !ADRESA_H
