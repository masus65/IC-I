//#pragma once
#ifndef OBJEKT_H
#define OBJEKT_H

// T�ida Objekt     
class Objekt {
private:
	int id; // Atributy : int id, double x, double y
	double x;
	double y;

public:
	Objekt(int id); // Parametrick� konstruktor : id - Neparametrick� konstruktor nevytv��et!
	virtual ~Objekt() {}; // Definujte virtu�ln� destruktor : virtual ~Objekt() { }

	double GetX() const; // Getter: x, y
	double GetY() const;
	double GetId() const; // Getter : id

	void SetX(double aX); // Setter : x, y
	void SetY(double aY);
};


#endif // !OBJEkT_H
