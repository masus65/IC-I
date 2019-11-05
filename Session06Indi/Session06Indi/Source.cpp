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
	for (int i = 0; i < velikost; i++){
		cout << osoby[i] << endl;
	}

}

//Ve funkci uloz() vytvoøte statické pole objektù Osoba(s alespoò 3 objekty) a zapište jej do souboru.
void uloz() {
	Osoba poleOsob[VELIKOST_POLE];
	Osoba O1{ "Paja","Novakova",Adresa { "jan","Praha",45542 },Datum { 1,2,2002 } };
	Osoba O2{ "Karel","Stary",Adresa { "Stara","Lutine",46122 },Datum { 3,4,2001 } };
	Osoba O3{ "Karla","Buchtova",Adresa { "Mlada","Ostrava",12130 },Datum { 4,5,2000 } };
	poleOsob[0] = O1;
	poleOsob[1] = O2;
	poleOsob[2] = O3;

	/*std::vector<Osoba> poleOsob;
	Osoba p1 = Osoba("Jan", "Novak", Adresa("Ulice1", "Mesto1", 111), Datum(1, 1, 1111));
	Osoba p2 = Osoba("Petr", "Novak", Adresa("Ulice2", "Mesto2", 222), Datum(2, 2, 2222));
	Osoba p3 = Osoba("Ivan", "Novak", Adresa("Ulice3", "Mesto3", 333), Datum(3, 3, 3333));
	poleOsob.push_back(p1);
	poleOsob.push_back(p2);
	poleOsob.push_back(p3);*/

	ofstream myFile;
	myFile.open("Session_06.txt");
	for (const auto& person : poleOsob)
	{
		myFile << person << std::endl;
	}
	myFile.close();
	std::cout << "Ulozeni dokonceno" << std::endl;

}

//Ve funkci nacti() naètìte osoby ze souboru do pole a vypište je na obrazovku.Pøi naèítání pole dynamicky alokujte, vhodným zpùsobem zjistìte poèet záznamù v souboru.
void nacti() {
	Osoba* osoby = new Osoba[VELIKOST_POLE];
	Osoba docasna;
	ifstream in{};
	int pocet = 0;
	in.open("Session_06.txt");
	if (in.is_open()) {
		for (int i = 0; i < VELIKOST_POLE; i++) {
				in >> docasna;
				osoby[i] = docasna;
		}
	}
	vypis(osoby,VELIKOST_POLE);

///////////////////////////
	/*std::vector<Osoba> osoby;
	Osoba temp;
	std::ifstream myFile("Session_06.txt");
	if (myFile.is_open())
	{
		while (myFile >> temp)
		{
			osoby.push_back(temp);
		}
		myFile.close();
	}
	else {
		std::cout << "Nelze otevrit soubor" << std::endl;
	}
	std::cout << "DATA LOADED" << std::endl;
	vypis(osoby);*/

}


//Ve funkci main volejte funkce uloz() a nacti().
int main() {
	uloz();
	nacti();
	return 0;
}