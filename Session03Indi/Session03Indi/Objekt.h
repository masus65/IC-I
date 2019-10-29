//#pragma once
#ifndef OBJEKT_H
#define OBJEKT_H

// T�ida Objekt     
class Objekt {
private:// Atributy : int id, double x, double y
	
	double x;
	double y;

public:
	int id;
	Objekt(int id); // Parametrick� konstruktor : id - Neparametrick� konstruktor nevytv��et!
	virtual ~Objekt() {}; // Definujte virtu�ln� destruktor : virtual ~Objekt() { }

	double GetX() const; // Getter: x, y
	double GetY() const;
	double GetId() const; // Getter : id

	void SetX(double aX); // Setter : x, y
	void SetY(double aY);
	void setId(int aId);
};


#endif // !OBJEkT_H
