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

string Laptop::getMatrix()
{
	return this->matrix;
}

void Laptop::setMatrix(string matrix)
{
	this->matrix = matrix;
}

istream& operator>>(istream& in, Laptop& obj)
{
	cout << "Enter model name (ex. Samsung): ";
	in >> obj.model;
	
	cout << "Enter battery value (ex. 1700): ";
	in >> obj.battery; 
	
	cout << "Enter matrix name (ex. TN-FILM): ";
	in >> obj.matrix;

	return in;
}

ostream& operator<<(ostream& os, const Laptop& obj)
{
	return os << setw(10) << obj.model << setw(10) << obj.battery << setw(10) << obj.matrix << endl;
}
