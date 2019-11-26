#include "Potrubi.h"
#include "PrvkyPotrubi.h"
#include "APotrubniPrvek.h"


Potrubi::Potrubi(std::istream & is) {
	is >> rozmer;

	prvky = new APotrubniPrvek*[rozmer*rozmer];
	
	for (int i = 0; i < rozmer*rozmer; i++)
		prvky[i] = nullptr;
	

	is.get();

	for (int i = 0; i < rozmer; i++){
		for (int j = 0; j < rozmer; j++){
			char znak = is.get();
			//znak = znak;

			APotrubniPrvek* prvek = nullptr;
			switch (znak){
			case ' ':
				break;

			case '-':
				prvek = new PrvekMinus{ j, i };
				break;

			case '+':
				prvek = new PrvekPlus{ j, i };
				break;

			case 'I':
				prvek = new PrvekI{ j, i };
				break;

			case 'T':
				prvek = new PrvekT{ j, i };
				break;

			case 'O':
				prvek = new PrvekO{ j, i };
				break;
			}

			prvky[i*rozmer + j] = prvek;

		}
		is.get();
	}
}


Potrubi::~Potrubi() {
	for (int i = 0; i < rozmer*rozmer; i++){
		if (prvky[i]) {
			delete prvky[i];
		}
	}
	delete[] prvky;
}

const APotrubniPrvek * Potrubi::DejPrvek(int x, int y) const {
	if (x < 0 || y < 0 || x >= rozmer || y >= rozmer) {
		return nullptr;
	}
	return prvky[y*rozmer + x];
}


bool Potrubi::JePotrubiOk() const {
	for (int i = 0; i < rozmer*rozmer; i++)
		if (prvky[i]) 
			if (!prvky[i]->JeKorektneZapojen(this)) 
				return false;
			
		return true;
	
}