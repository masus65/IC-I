#include <iostream>

//	Cvi�en� 01
//	1) Prvn� program
//			Vytvo�te program, kter� z kl�vesnice na�te strany troj�heln�ka a, b, c.Provede test, zda jde
//			sestrojit(a + b > c, a + c > b, b + c > a).Pokud jde sestrojit, pak vypi�te jeho obvod.
//			V opa�n�m p��pad� oznamte u�ivateli, �e takov� troj�heln�k sestrojit nelze.
//	2) Prvn� struktura
//			Vytvo�te strukturu Trojuhelnik, kter� obsahuje slo�ky int a, b, c.Upravte prvn� program tak,
//			aby vytvo�il objekt Trojuhelnik a do n�j na��tal jednotliv� hodnoty.Upravte test
//			sestrojitelnosti, tak aby to nyn� byla funkce : bool lzeSestrojit(Trojuhelnik t).
//	3) Prvn� ukazatel
//			Vytvo�te ukazatel Trojuhelnik* ukazatel, kter� bude ukazovat na na�ten� Trojuhelnik.
//			Na��tejte strany a, b, c p�es ukazatel.Vytvo�te funkci bool lzeSestrojit(Trojuhelnik* t).
//			A vyzkou�ejte ji pou��t.
//	4) Dynamick� pam�
//			Upravte program tak, aby nevytv��el instanci troj�heln�ku staticky, ale rovnou vytvo�te
//			pomoc� oper�toru new novou instanci do ukazatel.Nezapome�te na konci programu pam�
//			uvolnit pomoc� delete.
//	5) Pole v dynamick� pam�ti
//			Na za��tku se zeptejte u�ivatele, kolik chcete na��st troj�heln�k� a na z�klad� jeho volby
//			alokujte pole pomoc� new[].V cyklu na�t�te jednotliv� troj�heln�ky a na konci nezapome�te
//			na uvoln�n� pam�ti pomoc� delete[].


using namespace std;
struct trojuhelnik
{
	int a;
	int b;
	int c;

};

bool lzeSestrojit(trojuhelnik t) {
	if ((t.a + t.b > t.c) && (t.a + t.c > t.b) && (t.b + t.c > t.a)) {
		return true;
	}
	return false;
}

bool lzeSestrojit(trojuhelnik* t) {
	if ((t->a + t->b > t->c) && (t->a + t->c > t->b) && (t->b + t->c > t->a)) {
		return true;
	}
	return false;
}

int main() {
	//PROGRAM 1

	//int a, b, c; 
	//cout << "zadej a: " << endl;
	//cin >> a;
	//cout << "zadej b: " << endl;
	//cin >> b;
	//cout << "zadej c: " << endl;
	//cin >> c;

	//if ((a + b > c) && (a + c > b) && (b + c > a)) {
	//	cout << "Obvod: " << a + b + c << endl;

	//}
	//else
	//{
	//	cout << "Trojuhelnik nelze sestrojit"<< endl;
	//}





	//PROGRAM 2
	/*trojuhelnik t;


	cout << "zadej a: " << endl;
	cin >> t.a;
	cout << "zadej b: " << endl;
	cin >> t.b;
	cout << "zadej c: " << endl;
	cin >> t.c;
	if (lzeSestrojit(t))
	{
	cout << "Obvod: " << t.a + t.b + t.c << endl;
	}
	else
	{
	cout << "Trojuhelnik nelze sestrojit" << endl;
	}*/






	//PROGRAM 3
	/*trojuhelnik* t = new trojuhelnik;


	cout << "zadej a: " << endl;
	cin >> t->a;
	cout << "zadej b: " << endl;
	cin >> t->b;
	cout << "zadej c: " << endl;
	cin >> t->c;
	if (lzeSestrojit(t))
	{
	cout << "Obvod: " << t->a + t->b + t->c << endl;
	}
	else
	{
	cout << "Trojuhelnik nelze sestrojit" << endl;
	}*/






	//PROGRAM 4
	/*trojuhelnik* t = new trojuhelnik;


	cout << "zadej a: " << endl;
	cin >> t->a;
	cout << "zadej b: " << endl;
	cin >> t->b;
	cout << "zadej c: " << endl;
	cin >> t->c;
	if (lzeSestrojit(*t))
	{
	cout << "Obvod: " << t->a + t->b + t->c << endl;
	}
	else
	{
	cout << "Trojuhelnik nelze sestrojit" << endl;
	}
	delete(t);*/




	//PROGRAM 5 
	int pocetTrojuh;
	cout << "zadejte pocet trojuhelniku: " << endl;
	cin >> pocetTrojuh;
	trojuhelnik* poleTrojuhel = new trojuhelnik[pocetTrojuh];

	for (int i = 0; i < pocetTrojuh; i++)
	{
		trojuhelnik* t = new trojuhelnik;
		cout << "Zadejte trojuhelnik na indexu " << i << endl;
		poleTrojuhel[i] = *t;
		cout << "zadej a: ";
		cin >> poleTrojuhel[i].a;
		cout << "zadej b: ";
		cin >> poleTrojuhel[i].b;
		cout << "zadej c: ";
		cin >> poleTrojuhel[i].c;
		cout << endl;
		delete t;

	}

	for (int i = 0; i < pocetTrojuh; i++)
	{

		cout << "Trojuhelnik " << i << " a: " << poleTrojuhel[i].a << ", b: " << poleTrojuhel[i].b << ", c: " << poleTrojuhel[i].c << endl;
		if (lzeSestrojit(poleTrojuhel[i]))
		{
			cout << "Obvod: " << poleTrojuhel[i].a + poleTrojuhel[i].b + poleTrojuhel[i].c << endl;
		}
		else
		{
			cout << "Trojuhelnik nelze sestrojit" << endl;
		}
	}

	delete[] poleTrojuhel;
	return 0;
}