#pragma once
//#pragma once

#ifndef UCTENKA_H
#define UCTENKA_H

#include <string>

class Uctenka {
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	void zobrazUctenku();

	void SetCisloUctenky(int aCisloUctenky) { cisloUctenky = aCisloUctenky; };
	void SetCastka(double aCastka) { castka = aCastka; };
	void SetDph(double aDph) { dph = aDph; };

	int GetCisloUctenky() const { return cisloUctenky; };
	double GetCastka() const { return castka; };
	double GetDph() const { return dph; };

	std::string ToString() const { std::to_string(cisloUctenky) + std::to_string(castka); }
};

#endif // !UCTENKA_H