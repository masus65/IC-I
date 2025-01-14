#pragma once
#ifndef ADRESA_H
#define ADRESA_H
#include <string>
#include <iostream>

// Vytvorte strukturu Adresa (string _ulice, string _mesto, int _psc).
class Adresa {
private:
	std::string _ulice;
	std::string _mesto;
	int _psc;

public:
	Adresa(std::string aUlice, std::string aMesto, int aPsc);
	Adresa();
	friend std::ostream& operator<<(std::ostream& os, const Adresa& dt);
	friend std::istream& operator>>(std::istream& is, Adresa& dt);
	std::string getUlice() const { return _ulice; };
	std::string getMesto() const { return _mesto; };
	int getPsc() const { return _psc; };
};


#endif // !ADRESA_H