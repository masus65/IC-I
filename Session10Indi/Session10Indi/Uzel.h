#pragma once
#ifndef UZEL_H
#define UZEL_H
#include <string>
#include "ASitovyPrvek.h"

struct Uzel : public ASitovyPrvek {
public:
	Uzel(std::string adresa);
	~Uzel();

	void pripravZpravuKOdeslani(std::string cil, std::string obsah);

	virtual void provadej() override;
	virtual void pripoj(ASitovyPrvek* sitovyPrvek) override;

private:
	virtual void zpracujPrichoziZpravu(ZpravaPort zpravaPort) override;

	std::string _adresa;
	ASitovyPrvek* _pripojenyPrvek;
	Fronta<Zprava*> _odchoziZpravy;


	
	

};
#endif // !UZEL_H