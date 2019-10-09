#pragma once

#ifndef UCTENKA_H
#define UCTENKA_H

class Uctenka {
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	void zobrazUctenku();
	int getCisloUctenky() const;
	double getCastka() const;
	double getDph() const;

	void setCisloUctenky(int cisloUctenky);
	void setCastka(double castka);
	void setDph(double dph);
};

#endif // !UCTENKA_H