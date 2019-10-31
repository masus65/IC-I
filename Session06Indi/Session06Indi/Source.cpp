#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Osoba.h"


using namespace std;

//Ve funkci uloz() vytvo�te statick� pole objekt� Osoba(s alespo� 3 objekty) a zapi�te jej do souboru.
void uloz() {
	Osoba poleOsob[3];
	Osoba O1{ "Paj�","Novakov�",Adresa { "jan","Praha",45542 },Datum { 1,2,2002 } };
	Osoba O2{ "Karel","Star�",Adresa { "Stara","Lutin�",46122 },Datum { 3,4,2001 } };
	Osoba O3{ "Karla","Buchtov�",Adresa { "Mlada","Ostrava",12130 },Datum { 4,5,2000 } };

	poleOsob[0] = O1;
	poleOsob[1] = O2;
	poleOsob[2] = O3;

	ofstream out{};
	out.open("Session_06.txt");

	if (out.is_open())
	{
		for (int i = 0; i < 3; i++) {
			out << poleOsob[i]._jmeno << " " << poleOsob[i]._prijmeni << " adr. "
				<< poleOsob[i]._trvaleBydliste._ulice << " " << poleOsob[i]._trvaleBydliste._mesto << " " << poleOsob[i]._trvaleBydliste._psc << " nar. "
				<< poleOsob[i]._datumNarozeni._dne << ". " << poleOsob[i]._datumNarozeni._mesic << ". " << poleOsob[i]._datumNarozeni._rok << endl;
		}

		out.close();
	}
	else {
		throw std::exception("file not open!");
	}

}

//Ve funkci nacti() na�t�te osoby ze souboru do pole a vypi�te je na obrazovku.P�i na��t�n� pole dynamicky alokujte, vhodn�m zp�sobem zjist�te po�et z�znam� v souboru.
void nacti() {
	

}


//Ve funkci main volejte funkce uloz() a nacti().
int main() {
	uloz();
	nacti();
	return 0;
}