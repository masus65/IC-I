#include "PrvkyPotrubi.h"

bool PrvekMinus::JeKorektneZapojen(const IPotrubi * potrubi) const {
	return
		potrubi->DejPrvek(_x - 1, _y) != nullptr &&
		potrubi->DejPrvek(_x + 1, _y) != nullptr;
}

bool PrvekPlus::JeKorektneZapojen(const IPotrubi * potrubi) const {
	return
		potrubi->DejPrvek(_x - 1, _y) != nullptr &&
		potrubi->DejPrvek(_x + 1, _y) != nullptr &&
		potrubi->DejPrvek(_x, _y - 1) != nullptr &&
		potrubi->DejPrvek(_x, _y + 1) != nullptr;
}

bool PrvekI::JeKorektneZapojen(const IPotrubi * potrubi) const {
	return
		potrubi->DejPrvek(_x, _y - 1) != nullptr &&
		potrubi->DejPrvek(_x, _y + 1) != nullptr;
}

bool PrvekT::JeKorektneZapojen(const IPotrubi * potrubi) const {
	return
		potrubi->DejPrvek(_x - 1, _y) != nullptr &&
		potrubi->DejPrvek(_x + 1, _y) != nullptr &&
		potrubi->DejPrvek(_x, _y + 1) != nullptr;
}


bool PrvekO::JeKorektneZapojen(const IPotrubi * potrubi) const {
	return true;
}