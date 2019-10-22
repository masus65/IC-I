#include "TelefonniSeznam.h"

void Model::TelefonniSeznam::pridejOsobu(Entity::Osoba o)
{
	PrvekSeznamu* novyPrvekSeznamu = new PrvekSeznamu{};
	novyPrvekSeznamu->data = o;
	novyPrvekSeznamu->dalsi = _zacatek;
	_zacatek = novyPrvekSeznamu;
}

std::string Model::TelefonniSeznam::najdiTelefon(std::string jmeno) const
{
	if (jmeno._Equal(NULL))
		throw std::exception{""};
	PrvekSeznamu* prvekSeznamu = _zacatek;
	while (prvekSeznamu != nullptr) {
		if (prvekSeznamu->data.jmeno == jmeno)
			return prvekSeznamu->data.telefon;
		prvekSeznamu = prvekSeznamu->dalsi;
	}
	// TODO: throw an exception
	return NULL;
}

std::string Model::TelefonniSeznam::najdiTelefon(int id) const
{
	if (id == NULL)
		throw  std::exception{""};
	PrvekSeznamu* prvekSeznamu = _zacatek;
	while (prvekSeznamu != nullptr) {
		if (prvekSeznamu->data.id == id)
			return prvekSeznamu->data.telefon;
		prvekSeznamu = prvekSeznamu->dalsi;
	}
	// TODO: throw an exception
	return NULL;
}
