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
	obj.matrix = GetCorrectString(in, "Enter matrix name (ex. IPS): ", 10);
	return in;
}

ostream& operator<<(ostream& os, Laptop& obj)
{
	return os << dynamic_cast<Portative&>(obj) << setw(10) << obj.matrix << endl;
}

fstream& operator<<(fstream& out, Laptop& obj)
{
	out << dynamic_cast<Portative&>(obj);
	out << obj.matrix << '\n';
	return out;
}

//fstream& operator<< (fstream& out, const Laptop& obj) {
//	out.write(reinterpret_cast<const char*>(&obj), sizeof(obj)); // И никто больше не ругается.
//	return out;
//}

fstream& operator>>(fstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	getline(in, obj.matrix, '\n');
	return in;
}
