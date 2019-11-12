#include <iostream>
#include <fstream>
#include <stdexcept>
#include<vector>
#include "Osoba.h"
#include <string>
#define VELIKOST_POLE 3


using namespace std;

void vypis(std::vector<Osoba> osoba) {
	for (const auto& osoba : osoba) {
		std::cout << osoba << std::endl;
	}
}

void vypis(Osoba *osoby, int velikost) {
	for (int i = 0; i < velikost; i++) {
		cout << osoby[i] << endl;
	}

}

//Ve funkci uloz() vytvo�te statick� pole objekt� Osoba(s alespo� 3 objekty) a zapi�te jej do souboru.
void uloz() {
	/*Osoba poleOsob[VELIKOST_POLE];
	Osoba O1{ "Paja","Novakova",Adresa { "jan","Praha",45542 },Datum { 1,2,2002 } };
	Osoba O2{ "Karel","Stary",Adresa { "Stara","Lutine",46122 },Datum { 3,4,2001 } };
	Osoba O3{ "Karla","Buchtova",Adresa { "Mlada","Ostrava",12130 },Datum { 4,5,2000 } };
	poleOsob[0] = O1;
	poleOsob[1] = O2;
	poleOsob[2] = O3;*/
	
	Osoba* poleOsob = new Osoba[VELIKOST_POLE];
	Osoba O1{ "Paja","Novakova",Adresa { "jan","Praha",45542 },Datum { 1,2,2002 } };
	Osoba O2{ "Karel","Stary",Adresa { "Stara","Lutine",46122 },Datum { 3,4,2001 } };
	Osoba O3{ "Karla","Buchtova",Adresa { "Mlada","Ostrava",12130 },Datum { 4,5,2000 } };
	poleOsob[0] = O1;
	poleOsob[1] = O2;
	poleOsob[2] = O3;
	ofstream out{};
	out.open("session07.dat", ios_base::binary);

	if (out.is_open()) {
		for (int i = 0; i < VELIKOST_POLE; i++)
		{
			out.write((char*)&poleOsob[i], sizeof(Osoba));
		}
	}

}

//Ve funkci nacti() na�t�te osoby ze souboru do pole a vypi�te je na obrazovku.P�i na��t�n� pole dynamicky alokujte, vhodn�m zp�sobem zjist�te po�et z�znam� v souboru.
void nacti() {
	ifstream in{};
	in.open("session07.dat", ios_base::binary);
	string s{};
	//int count = 0;
	Osoba* osoby = new Osoba[3];
	if (in.is_open()) {
		/*while (!in.eof()) {
			getline(in,s);
			count++;
		}*/
		for (int i = 0; i < 3; i++)
		{
			in.read((char*)&osoby[i], sizeof(Osoba));
		}
		in.close();
	}
	vypis(osoby, VELIKOST_POLE);
	delete[] osoby;

}


//Ve funkci main volejte funkce uloz() a nacti().
int main() {
	uloz();
	nacti();
	return 0;
}