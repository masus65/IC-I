#pragma once
#ifndef HUB_H
#define HUB_H
#include "ASitovyPrvek.h"

class Hub : public ASitovyPrvek{
private:
	int _maximumPripojenychPrvku;
	ASitovyPrvek** _pripojenePrvky;
	Fronta<Zprava*> _zpracovaneZpravy;
	
	virtual void zpracujPrichoziZpravu(ZpravaPort zpravaPort) override;

public:
	Hub(int maximumPripojenychPrvku);
	~Hub();

	virtual void pripoj(ASitovyPrvek* sitovyPrvek) override;
	virtual void provadej() override;
	

};
#endif // !HUB_H