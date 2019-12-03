#pragma once
#ifndef SIT_H
#define SIT_H
#include "ASitovyPrvek.h"

struct Sit
{
public:
	static int dejNoveId();
	void pripoj(ASitovyPrvek* sitovyPrvek);
	void provadejVse(); 
private:
	static void nejakSeJmenuje(ASitovyPrvek* sitovyPrvek);

	static int _idZpravy;
	Fronta<ASitovyPrvek*> _sitovePrvky;
};
#endif // !SIT_H