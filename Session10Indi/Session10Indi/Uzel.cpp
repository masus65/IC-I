#include "Uzel.h"
#include "Sit.h"
#include<iostream>
using namespace std;

Uzel::Uzel(std::string adresa){
	this->_adresa = adresa;
}

void Uzel::pripravZpravuKOdeslani(std::string cil, std::string obsah){
	Zprava* novaZprava = new Zprava{ Sit::dejNoveId(), _adresa, cil, obsah };

	_odchoziZpravy.Vloz(novaZprava);
}

void Uzel::provadej(){
	while (!_odchoziZpravy.JePrazdna()) {
		Zprava* zpravakOdeslani = _odchoziZpravy.Odeber();
		
		_pripojenyPrvek->vlozPrichoziZpravu(zpravakOdeslani, this);
	}

	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort prichoziZprava = prichoziZpravy.Odeber();

		zpracujPrichoziZpravu(prichoziZprava);
	}

}

void Uzel::pripoj(ASitovyPrvek * sitovyPrvek){
	_pripojenyPrvek = sitovyPrvek;

}

void Uzel::zpracujPrichoziZpravu(ZpravaPort zpravaPort){
	if (zpravaPort.zprava->adrCil != _adresa)
		return;

	cout << _adresa << " REVC id: " << zpravaPort.zprava->id << "src:" << zpravaPort.zprava->adrZdroj << " obsah: " << zpravaPort.zprava->obsah << endl;

	if (zpravaPort.zprava->obsah == "ping") {
		pripravZpravuKOdeslani(zpravaPort.zprava->adrZdroj, "pong");
	}
}
