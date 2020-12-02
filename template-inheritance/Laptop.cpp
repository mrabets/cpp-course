#include "Laptop.h"

Laptop::Laptop() : Portative()
{
	this->matrix = "ips";
	count++;
}

Laptop::Laptop(string matrix, int battery, string model) : Portative(battery, model)
{
	this->matrix = matrix;
	count++;
}

Laptop::Laptop(const Laptop& object) : Portative(object)
{
	this->matrix = object.matrix;
}

Laptop::~Laptop()
{
	count--;
}

string Laptop::getMatrix() const
{
	return this->matrix;
}

int Laptop::getCount()
{
	return count;
}

void Laptop::setMatrix(string matrix)
{
	this->matrix = matrix;
}

istream& operator>>(istream& in, Laptop& obj)
{	
	in >> dynamic_cast<Portative&>(obj);

	cout << "Enter matrix name (ex. TN-FILM): ";
	in >> obj.matrix;

	return in;
}

ostream& operator<<(ostream& os, Laptop& obj)
{
	return os << dynamic_cast<Portative&>(obj) << setw(10) << obj.matrix << endl;
}
