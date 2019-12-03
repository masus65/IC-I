#pragma once
#ifndef A_SITOVY_PRVEK_H
#define A_SITOVY_PRVEK_H
#include "Zprava.h"
#include "ZpravaPort.h"
#include "Fronta.h"

struct ASitovyPrvek {

public:
	void vlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void provadej() = 0;
	virtual void pripoj(ASitovyPrvek* sitovyPrvek) = 0;

protected:
	virtual void zpracujPrichoziZpravu(ZpravaPort zpravaPort) = 0;
	Fronta<ZpravaPort> prichoziZpravy;
};
#endif // !A_SITOVY_PRVEK_H