#include "Hub.h"
#include "Uzel.h"
#include "Sit.h"

int main()
{
	Sit* s = new Sit{ };
	Hub* h1 = new Hub{ 8 };
	Hub* h2 = new Hub{ 8 };
	Hub* h3 = new Hub{ 8 };
	Hub* h4 = new Hub{ 16 };
	Hub* h5 = new Hub{ 24 };
	Uzel* u1 = new Uzel{ "a1" };
	Uzel* u2 = new Uzel{ "a2" };
	Uzel* u3 = new Uzel{ "a3" };
#define propoj(a,b) a->pripoj(b); b->pripoj(a)
#define propojs(a,b,c) propoj(a,b); c->pripoj(a); c->pripoj(b)
	propojs(u1, h1, s);
	propojs(u2, h3, s);
	propojs(u3, h5, s);
	propojs(h1, h2, s);
	propojs(h2, h3, s);
	propojs(h1, h4, s);
	propojs(h4, h5, s);
	propojs(h5, h2, s);
	u1->pripravZpravuKOdeslani("a2", "ping");
	u1->pripravZpravuKOdeslani("a3", "ping");
	for (int i = 0; i < 100; i++)
		s->provadejVse();
	return 0;
}