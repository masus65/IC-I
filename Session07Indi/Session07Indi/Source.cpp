#include <iostream>
#include <fstream>
#include <stdexcept>
#include<vector>
#include "Osoba.h"
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
	Osoba poleOsob[VELIKOST_POLE];
	Osoba O1{ "Paja","Novakova",Adresa { "jan","Praha",45542 },Datum { 1,2,2002 } };
	Osoba O2{ "Karel","Stary",Adresa { "Stara","Lutine",46122 },Datum { 3,4,2001 } };
	Osoba O3{ "Karla","Buchtova",Adresa { "Mlada","Ostrava",12130 },Datum { 4,5,2000 } };
	poleOsob[0] = O1;
	poleOsob[1] = O2;
	poleOsob[2] = O3;

	std::streampos size;
	char* memblock;
	std::ifstream myFile("Session07.bin", std::ios::in | std::ios::binary | std::ios::ate);
	if (myFile.is_open)
	{
		size = myFile.tellg();
		memblock = new char[size];
		myFile.seekg(0, std::ios::beg);
		myFile.read(memblock, size);
		myFile.close();
		std::cout << "The entire thing is in memory";
		delete[] memblock;
	}
	else {
		std::cout << "Error, unable to open file";
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