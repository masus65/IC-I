//#pragma once
#ifndef _OSOBA_H
#define _OSOBA_H
#include <string>


//Vytvoøte tøídu Osoba(atributy string jmeno, string telefon, int id) ve jmenném prostoru Entity.
namespace Entity{
	class Osoba {
	public:
		std::string jmeno;
		std::string telefon;
		int id;

	public:
		//Osoba() : jmeno(""), telefon(""), id(0) {}
	};
}
#endif // !_OSOBA_H
