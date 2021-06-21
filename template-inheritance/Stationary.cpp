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

	obj.powerSupply = GetCorrectNumber<float>(in, "Enter power supply in Watt (ex. 5250.25): ", 50.0f, 10000.0f);

	return in;
}

ostream& operator<<(ostream& os, const Stationary& obj)
{
	return os << dynamic_cast<const VMachine&>(obj) << setw(10) << obj.powerSupply;
}

fstream& operator<<(fstream& out, Stationary& obj)
{
	out << dynamic_cast<VMachine&>(obj);
	out << obj.powerSupply << " ";
	return out;
}

fstream& operator>>(fstream& in, Stationary& obj)
{
	in >> dynamic_cast<VMachine&>(obj);
	in >> obj.powerSupply;
	return in;
}

ofstream& operator<<(ofstream& out, Stationary& obj)
{
	out << dynamic_cast<VMachine&>(obj);
	out.write(reinterpret_cast<char*>(&obj.powerSupply), sizeof(obj.powerSupply));
	return out;
}

ifstream& operator>>(ifstream& in, Stationary& obj)
{
	in >> dynamic_cast<VMachine&>(obj);
	in.read(reinterpret_cast<char*>(&obj.powerSupply), sizeof(obj.powerSupply));
	return in;
}
