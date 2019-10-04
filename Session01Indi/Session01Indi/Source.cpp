#include <iostream>

//	Cvièení 01
//	1) První program
//			Vytvoøte program, který z klávesnice naète strany trojúhelníka a, b, c.Provede test, zda jde
//			sestrojit(a + b > c, a + c > b, b + c > a).Pokud jde sestrojit, pak vypište jeho obvod.
//			V opaèném pøípadì oznamte uživateli, že takový trojúhelník sestrojit nelze.
//	2) První struktura
//			Vytvoøte strukturu Trojuhelnik, která obsahuje složky int a, b, c.Upravte první program tak,
//			aby vytvoøil objekt Trojuhelnik a do nìj naèítal jednotlivé hodnoty.Upravte test
//			sestrojitelnosti, tak aby to nyní byla funkce : bool lzeSestrojit(Trojuhelnik t).
//	3) První ukazatel
//			Vytvoøte ukazatel Trojuhelnik* ukazatel, který bude ukazovat na naètený Trojuhelnik.
//			Naèítejte strany a, b, c pøes ukazatel.Vytvoøte funkci bool lzeSestrojit(Trojuhelnik* t).
//			A vyzkoušejte ji použít.
//	4) Dynamická pamì
//			Upravte program tak, aby nevytváøel instanci trojúhelníku staticky, ale rovnou vytvoøte
//			pomocí operátoru new novou instanci do ukazatel.Nezapomeòte na konci programu pamì
//			uvolnit pomocí delete.
//	5) Pole v dynamické pamìti
//			Na zaèátku se zeptejte uživatele, kolik chcete naèíst trojúhelníkù a na základì jeho volby
//			alokujte pole pomocí new[].V cyklu naètìte jednotlivé trojúhelníky a na konci nezapomeòte
//			na uvolnìní pamìti pomocí delete[].


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