//#pragma once
#ifndef PRVKYPOTRUBI_H
#define PRVKYPOTRUBI_H
#include "APotrubniPrvek.h"

struct PrvekMinus : public APotrubniPrvek {
	PrvekMinus(int x, int y) {
		_x = x;
		_y = y;
	}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;

};

struct PrvekPlus : public APotrubniPrvek {
	PrvekPlus(int x, int y) {
		_x = x;
		_y = y;
	}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;

};

struct PrvekI : public APotrubniPrvek {
	PrvekI(int x, int y) {
		_x = x;
		_y = y;
	}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;

};

struct PrvekT : public APotrubniPrvek {
	PrvekT(int x, int y) {
		_x = x;
		_y = y;
	}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;

};

struct PrvekO : public APotrubniPrvek{
	PrvekO(int x, int y) { 
		_x = x; 
		_y = y; 
	}
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;

};

#endif // !PRVKYPOTRUBI_H
