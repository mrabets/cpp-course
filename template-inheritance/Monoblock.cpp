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

string Monoblock::getStandColour() const
{
	return this->standColour;
}

void Monoblock::setStandColour(string standColour)
{
	this->standColour = standColour;
}

istream& operator>>(istream& in, Monoblock& obj)
{
	in >> dynamic_cast<Stationary&>(obj);

	cout << "Enter the stand colour (ex. Green): ";
	in >> obj.standColour;

	return in;
}

ostream& operator<<(ostream& os, Monoblock& obj)
{
	return os << dynamic_cast<Stationary&>(obj) << setw(10) << obj.standColour << endl;
}
