#include "Stationary.h"

Stationary::Stationary()
{
	this->powerSupply = 0;
}

Stationary::Stationary(double powerSupply, string model) : VMachine(model)
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

double Stationary::getPowerSupply() const
{
	return this->powerSupply;
}

void Stationary::setPowerSupply(double powerSupply)
{
	this->powerSupply = powerSupply;
}

istream& operator>>(istream& in, Stationary& obj)
{
	in >> dynamic_cast<VMachine&>(obj);

	obj.powerSupply = GetCorrectNumber<double>(in, "Enter power supply (ex. 5250.25): ");

	return in;
}

ostream& operator<<(ostream& os, Stationary& obj)
{
	return os << dynamic_cast<VMachine&>(obj) << setw(10) << obj.powerSupply;
}
