#include "Hub.h"

void Hub::zpracujPrichoziZpravu(ZpravaPort zpravaPort){
	if (_zpracovaneZpravy.Obsahuje(zpravaPort.zprava))
		return;

	for (int i = 0; i < _maximumPripojenychPrvku; i++){
		if (_pripojenePrvky[i] != nullptr) {
			if (_pripojenePrvky[i] != zpravaPort.port) {
				_pripojenePrvky[i]->vlozPrichoziZpravu(zpravaPort.zprava, this);
			}
		}
	}
	_zpracovaneZpravy.Vloz(zpravaPort.zprava);
}

Hub::Hub(int maximumPripojenychPrvku)
{
	_maximumPripojenychPrvku = maximumPripojenychPrvku;
	_pripojenePrvky = new ASitovyPrvek*[maximumPripojenychPrvku];
	for (int i = 0; i < maximumPripojenychPrvku; i++){
		_pripojenePrvky[i] = nullptr;
	}
}

Hub::~Hub(){
	delete[] _pripojenePrvky;
}

void Hub::pripoj(ASitovyPrvek * sitovyPrvek){
	for (int i = 0; i < _maximumPripojenychPrvku; i++){
		if (_pripojenePrvky[i] == nullptr) {
			_pripojenePrvky[i] = sitovyPrvek;
			break;
		}

	}
}

void Hub::provadej(){
	while (!prichoziZpravy.JePrazdna()) {
		ZpravaPort zp = prichoziZpravy.Odeber();

		zpracujPrichoziZpravu(zp);
	}
}
