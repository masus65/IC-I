#include <iostream>
#include <string>
#include "Uctenka.h"
#include "Pokladna.h"

//  Ve funkci main() tøídy otestujte – vytvoøte instanci tøídy Pokladna a následnì vystavte
//  alespoò 3 rùzné úètenky.Vyzkoušejte manipulaci s úètenkou vrácenou metodou
//  vystavUctenku() a následnì voláním dejUctenku().
//  Vypoèítejte a vypište celkovou èástku a celkovou èástku bez dph z pokladny.

using namespace std;

//void Foo(const Pokladna& aPokladna) {
//	aPokladna.
//}


int main(int argc, char** argv) {

	Pokladna pokladna{};

	Uctenka& uctenka1 =
		pokladna.vystavUctenku(5, 0.22);
	Uctenka& uctenka2 =
		pokladna.vystavUctenku(20, 0.22);
	Uctenka& uctenka3 =
		pokladna.vystavUctenku(30, 0.22);

	uctenka1.SetCastka(10);
	pokladna.vystavUctenku(40, 0.22);
	Uctenka& uctenka4 = pokladna.dejUctenku(1003);
	uctenka1.zobrazUctenku();
	uctenka2.zobrazUctenku();
	uctenka3.zobrazUctenku();
	uctenka4.zobrazUctenku();

	cout << endl << "Celkova castka: " << pokladna.dejCastku() << endl << "Celkova castka vcetne dph: " << pokladna.dejCastkuVcDph();
	cout << endl;
	system("pause");
	return 0;
}
