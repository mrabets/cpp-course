#include "Tablet.h"

Tablet::Tablet()
{
	this->stylus = 0;
}

Tablet::Tablet(bool stylus, int battery, string model) : Portative(battery, model)
{
	this->stylus = stylus;
}

Tablet::Tablet(const Tablet& object) : Portative(object)
{
	this->stylus = object.stylus;
}

Tablet::~Tablet()
{
}

bool Tablet::isStylus()
{
	return this->stylus;
}

void Tablet::setStylus(bool stylus)
{
	this->stylus = stylus;
}

istream& operator>>(istream& in, Tablet& obj)
{
	cout << "Enter model name: ";
	in >> obj.model;

	cout << "Enter battery value: ";
	in >> obj.battery;

	cout << "Has it stylus?: ";
	in >> obj.stylus;

	return in;
}

ostream& operator<<(ostream& os, const Tablet& obj)
{
	return os << setw(10) << obj.model << setw(10) << obj.battery << setw(10) << obj.stylus << endl;
}