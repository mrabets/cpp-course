#pragma once
#include "Portative.h"

class Laptop : public Portative
{
public:
	Laptop();
	Laptop(string matrix, int battery, string model);
	Laptop(const Laptop& object);
	~Laptop();

	string getMatrix() const;
	void setMatrix(string matrix);

	friend istream& operator >> (istream& in, Laptop& obj);
	friend ostream& operator << (ostream& os, Laptop& obj);

private:
	string matrix;
};

