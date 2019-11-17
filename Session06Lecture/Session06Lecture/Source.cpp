#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define VELIKOST_RETEZCE 6

void uloz() {
	ofstream binarniSoubor{ "soubor.dat", ios_base::out | ios_base::binary };


#define z(x) binarniSoubor.write((char*)&(x), sizeof(x))
	//binarniSoubor.write((char*)&cislo, sizeof cislo);
	int cislo = 1000;
	z(cislo);
	char znak = 'B';
	z(znak);
	double dcislo = 3.141592;
	z(cislo);
	float fcislo = 2.59f;
	z(fcislo);
	bool logickaHodnota = true;
	z(logickaHodnota);
	unsigned short int hahah = 123;
	z(hahah);

	binarniSoubor.seekp(32);

	int poleOsklivychIntegeru[] = { 10, 1,12,13,14,15,2,0,1,5 };
	z(poleOsklivychIntegeru);


	binarniSoubor.close();

}

void nacti() {
	ifstream binarniSoubor("soubor.dat", ios_base::in | ios_base::binary);

	int cislo = 0;
	binarniSoubor.read((char*)&cislo, sizeof cislo);
	cout << "Cislo: " << cislo << endl;
	binarniSoubor.seekg(1, ios_base::cur);

	char* znaky = new char[sizeof(double)];
	binarniSoubor.read(znaky, sizeof(double));
	cout << "Double hodnota: " << (*(double*)znaky) << endl;
	delete[] znaky;

	binarniSoubor.seekg(32);

	int* pole = new int[10];
	//binarniSoubor.read((char*)pole, 10 * sizeof(int));
	for (int i = 0; i < 10; i++){
		binarniSoubor.read((char*)(pole + i), sizeof(int));
	}

	for (int i = 0; i < 10; i++){
		cout << pole[i] << ", ";
	}
	cout << endl;

	delete[] pole;


	cin.get();

	binarniSoubor.close();
}

//_declspec(align(32))
struct Barva{
	int r, g, b;
	int jas;
	char* nazev;
	string lepsiNazev;
};

void ulozStrukturu() {
	ofstream f{ "soubor.dat", ios_base::out | ios_base::binary };

	Barva oskliva{ 120, 250, 30, 0xfffffff, "Oskliva barva", string{"Oskliva barva to je" } };
	f.write((char*)&oskliva, sizeof oskliva);

	f.seekp(48);

#define VELIKOST_RETEZCE 6

	string s{ oskliva.nazev };
	s.resize(VELIKOST_RETEZCE);

	f.write(s.c_str(), s.size());
	//f.write(oskliva.nazev, strlen(oskliva.nazev) + 1);
	//f.write(oskliva.nazev, strlen(oskliva.nazev) + 1);
	//f.write(oskliva.nazev, strlen(oskliva.nazev) + 1);

	f.close();
}

void nactiStrukturu() {
	ifstream f{ "soubor.dat", ios_base::in | ios_base::binary };

	f.seekg(48);

	char retezec[VELIKOST_RETEZCE];
	f.read(retezec, sizeof(retezec));
	
	string s{retezec, VELIKOST_RETEZCE };
	
	cout << "Nacteno: " << s << endl;
	cin.get();

	f.close();
}



int main() {

	//uloz();
	//nacti();
	ulozStrukturu();
	nactiStrukturu();


	return 0;
}