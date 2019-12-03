#include "ASitovyPrvek.h"

void ASitovyPrvek::vlozPrichoziZpravu(Zprava * zprava, ASitovyPrvek * port)
{
	ZpravaPort zp{ zprava, port };
	prichoziZpravy.Vloz(zp);
}
