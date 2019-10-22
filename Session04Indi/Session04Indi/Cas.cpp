#include "Cas.h"
#include <iostream>
#include <string>

using namespace std;

Cas::Cas(int _aHodiny, int _aMinuty, int _aSekundy) : _hodiny(_aHodiny),_minuty(_aMinuty) ,_sekundy(_aSekundy){
	//this->_hodiny = _aHodiny;
	//this->_minuty = _aMinuty;
	//this->_sekundy = _aSekundy;
}

std::string Cas::toString() const
{
	return std::to_string(this->_hodiny) + ':' + std::to_string(this->_minuty) + ':' + std::to_string(this->_sekundy);
}



int Cas::compareTo(IComparable * obj) const
{
	if (_hodiny == ((Cas*)obj)->_hodiny) {
		if (_minuty == ((Cas*)obj)->_minuty) {
			if (_sekundy == ((Cas*)obj)->_sekundy) {
				return 0;
			}
			else if (_sekundy > ((Cas*)obj)->_sekundy) {
				return 1;
			}
			else {
				return -1;
			}
		}
		else if(_minuty > ((Cas*)obj)->_minuty){
		return 1;
		}
		else {
		return -1;
		}
	}
	else if (_hodiny > ((Cas*)obj)->_hodiny) {
		return 1;
	}
	else {
		return -1;
	}

}



