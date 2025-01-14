//#pragma once
#ifndef DATUM_H
#define DATUM_H
#include <iostream>

//Vytvorte strukturu Datum(int _den, int _mesic, int _rok).
class Datum {
private:
	int _dne;
	int _mesic;
	int _rok;

public:
	Datum(int aDen, int aMesic, int aRok);
	Datum();
	~Datum();
	friend std::ostream& operator<<(std::ostream& os, const Datum& d);
	friend std::istream& operator>>(std::istream& is, Datum& d);
	int getDne() const { return _dne; };
	int getMesic() const { return _mesic; };
	int getRok() const { return _rok; };

};

#endif // !DATUM_H