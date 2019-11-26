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

//Ve funkci uloz() vytvoøte statické pole objektù Osoba(s alespoò 3 objekty) a zapište jej do souboru.
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

	/////////////////////////
	Osoba people[VELIKOST_POLE] = { Osoba("Name1", "lastName1", Adresa("Street1", "City1", 111), Datum(1, 1, 1111)),
									Osoba("Name2", "lastName2", Adresa("Street2", "City2", 222), Datum(2, 2, 2222)),
									Osoba("Name3", "lastName3", Adresa("Street3", "City3", 333), Datum(3, 3, 3333)) };

	std::ofstream binFile("session07-2.dat", std::ios::binary);
	if (binFile.is_open())
	{
		for (int i = 0; i < VELIKOST_POLE; i++)
		{
			people[i].write(&binFile);
		}
		binFile.close();

		std::cout << "ulozeno";
	}
	else
	{
		throw std::exception("soubor neotevren");
	}

}

//Ve funkci nacti() naètìte osoby ze souboru do pole a vypište je na obrazovku.Pøi naèítání pole dynamicky alokujte, vhodným zpùsobem zjistìte poèet záznamù v souboru.
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


	////////////////////////////////////////////
	/*Osoba temp;

	std::ifstream binFile("session07-2.dat", std::ios::binary);
	if (binFile.is_open())
	{
		Osoba* nacteneOsoby = new Osoba[0];
		int numberOfObjects = 0;
		for (int i = 0; i < 3; i++)
		{
			Osoba* docasnaOsoba = new Osoba[numberOfObjects + 1];
			docasnaOsoba = nacteneOsoby;

			nacteneOsoby = new Osoba[numberOfObjects + 1];
			for (int i = 0; i < numberOfObjects; i++)
			{
				nacteneOsoby[i] = docasnaOsoba[i];
			}
			temp.read(&binFile);
			nacteneOsoby[numberOfObjects] = temp;
			numberOfObjects++;
			delete[] docasnaOsoba;
		}

		binFile.close();
		std::cout << "DATA LOADED" << std::endl;
		vypis(nacteneOsoby, numberOfObjects);
		delete[] nacteneOsoby;
	}*/

}


//Ve funkci main volejte funkce uloz() a nacti().
int main() {
	uloz();
	nacti();
	return 0;
}