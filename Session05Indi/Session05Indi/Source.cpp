#include <iostream>
#include "TelefonniSeznam.h"
#include "Osoba.h"
#include "Exception.h"
#include <exception>

using namespace Model;
using namespace Entity;
using namespace std;

int main(int argc, char** argv)
{
	try {

		TelefonniSeznam seznam{};

		Osoba o1 = Osoba{ "Marek", "786212",0 };
		Osoba o2 = Osoba{ "Jana", "75462",1 };
		Osoba o3 = Osoba{ "Karla", "765112",2 };
		Osoba o4 = Osoba{ "Michael", "24542",3 };
		Osoba o5 = Osoba{ "Steve", "7856612",4 };

		seznam.pridejOsobu(o1);
		seznam.pridejOsobu(o2);
		seznam.pridejOsobu(o3);
		seznam.pridejOsobu(o4);
		seznam.pridejOsobu(o5);

		cout << "Telefon osoby s id 3 je: " << seznam.najdiTelefon(3) << endl;
		cout << "Telefon osoby s se Jmenem Steve je: " << seznam.najdiTelefon("Steve") << endl;

		seznam.najdiTelefon(6);


	}
	catch (WrongInputException & ex) {
		cout << ex.getMessage() << endl;
	}
	catch (NoSuchElementException & ex) {
		cout << ex.getMessage() << endl;
	}
}