#pragma once
#include "Portative.h"

class Laptop : public Portative
{
public:
	Laptop();
	Laptop(string matrix, int battery, string model);
	Laptop(const Laptop& object);
	~Laptop();

	string getMatrix();
	void setMatrix(string matrix);

	friend istream& operator >> (istream& in, Laptop& obj);
	friend ostream& operator << (ostream& os, const Laptop& obj);

private:
	string matrix;
};

