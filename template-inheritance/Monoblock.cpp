#include "Monoblock.h"

Monoblock::Monoblock()
{
	this->standColour = "empty";
}

Monoblock::Monoblock(string standColour, int powerSupply, string model) : Stationary(powerSupply, model)
{
	this->standColour = standColour;
}

Monoblock::Monoblock(const Monoblock& object) : Stationary(object)
{
	this->standColour = object.standColour;
}

Monoblock::~Monoblock()
{

}

string Monoblock::getStandColour()
{
	return this->standColour;
}

void Monoblock::setStandColour(string standColour)
{
	this->standColour = standColour;
}

istream& operator>>(istream& in, Monoblock& obj)
{
	cout << "Enter model name: ";
	in >> obj.model;

	cout << "Enter power supply: ";
	in >> obj.powerSupply;

	cout << "Enter the stand colour: ";
	in >> obj.standColour;

	return in;
}

ostream& operator<<(ostream& os, const Monoblock& obj)
{
	return os << setw(10) << obj.model << setw(10) << obj.powerSupply << setw(10) << obj.standColour << endl;
}
