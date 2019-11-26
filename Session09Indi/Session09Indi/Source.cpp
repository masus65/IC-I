#include <iostream>
#include <sstream>
#include <string>
#include "Potrubi.h"


using namespace std;

int main() {

	string vstup = 
		string{ "5" } + "\n" +
		" O-O " + "\n" +
		"O--+O" + "\n" +
		"   I " + "\n" +
		" O I " + "\n" +
		"   O ";
	istringstream iss{ vstup };


	Potrubi potrubi{ iss };

	cout << (potrubi.JePotrubiOk() ? "FUNGUJE" : "ROZBITE!!!") << endl;
	

	cin.get();

	return 0;

	};
