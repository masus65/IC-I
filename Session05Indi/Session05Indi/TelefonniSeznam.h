//#pragma once
#ifndef _TELEFONNISEZNAM_H
#define _TELEFONNISEZNAM_H
#include "Osoba.h"

// Vytvoøte tøídu TelefonniSeznam(jmenný prostor Model), která realizuje ADS tabulka, kde klíèem je
// id / jméno osoby a hledanou hodnotou je telefon.Pro implementaci tabulky vytvoøte strukturu spojový seznam.
namespace Model {
	class TelefonniSeznam {
	public:
		class PrvekSeznamu {
		private:

		public:
			PrvekSeznamu* dalsi;
			Entity::Osoba data;
			PrvekSeznamu() : dalsi(nullptr), data() {}
		};

	private:
		PrvekSeznamu* _zacatek; // Atributy: PrvekSeznam * _zacatek

	public:
		void pridejOsobu(Entity::Osoba o); // o Pøidá osobu do seznamu
		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const; // Pokud je jméno osoby prázdné nebo id záporné je vyvolána výjimky oznamující  neplatný vstupní parametr.  Pokud zadaná osoba není v seznamu, metody vyvolají výjimku.

// Výjimky budou reprezentovány vhodnými tøídami(využijte standardní knihovnu nebo implementujte vlastní, vyvolané výjimky musí reprezentovat dvì rùzné tøídy se spoleèným pøedkem).

	};
}
#endif // !_TELEFONNISEZNAM_H
