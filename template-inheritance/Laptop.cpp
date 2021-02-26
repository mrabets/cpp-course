#include "Laptop.h"

Laptop::Laptop() : Portative()
{
	this->matrix = "ips";
}

Laptop::Laptop(string matrix, int battery, string model) : Portative(battery, model)
{
	this->matrix = matrix;
}

Laptop::Laptop(const Laptop& object) : Portative(object)
{
	this->matrix = object.matrix;
}

Laptop::~Laptop()
{
}

string Laptop::getMatrix() const
{
	return this->matrix;
}

void Laptop::setMatrix(string matrix)
{
	this->matrix = matrix;
}

istream& operator>>(istream& in, Laptop& obj)
{	
	in >> dynamic_cast<Portative&>(obj);
	
	obj.matrix = GetCorrectString(in, "Enter matrix name (ex. IPS): ");
	
	return in;
}

ostream& operator<<(ostream& os, Laptop& obj)
{
	return os << dynamic_cast<Portative&>(obj) << setw(10) << obj.matrix << endl;
}
