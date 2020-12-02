#include "Stationary.h"

Stationary::Stationary()
{
	this->powerSupply = 0;
}

Stationary::Stationary(int powerSupply, string model) : VMachine(model)
{
	this->powerSupply = powerSupply;
}

Stationary::Stationary(const Stationary& object) : VMachine(object)
{
	this->powerSupply = object.powerSupply;
}

Stationary::~Stationary()
{
}

int Stationary::getPowerSupply() const
{
	return this->powerSupply;
}

void Stationary::setPowerSupply(int powerSupply)
{
	this->powerSupply = powerSupply;
}

istream& operator>>(istream& in, Stationary& obj)
{
	in >> dynamic_cast<VMachine&>(obj);

	cout << "Enter power supply (ex. 5000): ";
	in >> obj.powerSupply;

	return in;
}

ostream& operator<<(ostream& os, Stationary& obj)
{
	return os << dynamic_cast<VMachine&>(obj) << setw(10) << obj.powerSupply;
}
