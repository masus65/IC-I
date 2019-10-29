#include "Objekt.h"

Objekt::Objekt(int id)
{
	this->id = id;
}

double Objekt::GetX() const
{
	return this->x;
}

double Objekt::GetY() const
{
	return this->y;
}

double Objekt::GetId() const
{
	return this->id;
}

void Objekt::SetX(double aX)
{
	this->x = aX;
}

void Objekt::SetY(double aY)
{
	this->y = aY;
}

void Objekt::setId(int aId)
{
	this->id = aId;
}
