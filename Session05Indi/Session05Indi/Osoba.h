//#pragma once
#ifndef _OSOBA_H
#define _OSOBA_H
#include <string>


//Vytvoøte tøídu Osoba(atributy string jmeno, string telefon, int id) ve jmenném prostoru Entity.
namespace Entity{
	class Osoba {
	private:
		std::string jmeno;
		std::string telefon;
		int id;

	public:
		Osoba();
		Osoba(std::string jmeno, std::string telefon, int id);
		~Osoba();

		int getId() const;
		std::string getJmeno() const;
		std::string getTelefon() const;
	};
}
#endif // !_OSOBA_H
