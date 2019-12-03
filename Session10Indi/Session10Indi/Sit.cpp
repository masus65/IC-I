#include "Sit.h"

int Sit::_idZpravy = 0;

int Sit::dejNoveId(){

	return _idZpravy++;
}

void Sit::pripoj(ASitovyPrvek * sitovyPrvek){
	if (!_sitovePrvky.Obsahuje(sitovyPrvek)) {
		_sitovePrvky.Vloz(sitovyPrvek);
	}
}

void Sit::provadejVse(){
	_sitovePrvky.ZpracujPrvky(Proved);
	//_sitovePrvky.ZpracujPrvky([](ASitovyPrvek* sp) {sp->provadej(); });
}

void Sit::Proved(ASitovyPrvek * sitovyPrvek){
	sitovyPrvek->provadej();
}
