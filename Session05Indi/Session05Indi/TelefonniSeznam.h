//#pragma once
#ifndef _TELEFONNISEZNAM_H
#define _TELEFONNISEZNAM_H
#include "Osoba.h"

// Vytvo�te t��du TelefonniSeznam(jmenn� prostor Model), kter� realizuje ADS tabulka, kde kl��em je
// id / jm�no osoby a hledanou hodnotou je telefon.Pro implementaci tabulky vytvo�te strukturu spojov� seznam.
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
		void pridejOsobu(Entity::Osoba o); // o P�id� osobu do seznamu
		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const; // Pokud je jm�no osoby pr�zdn� nebo id z�porn� je vyvol�na v�jimky oznamuj�c�  neplatn� vstupn� parametr.  Pokud zadan� osoba nen� v seznamu, metody vyvolaj� v�jimku.

// V�jimky budou reprezentov�ny vhodn�mi t��dami(vyu�ijte standardn� knihovnu nebo implementujte vlastn�, vyvolan� v�jimky mus� reprezentovat dv� r�zn� t��dy se spole�n�m p�edkem).

	};
}
#endif // !_TELEFONNISEZNAM_H
