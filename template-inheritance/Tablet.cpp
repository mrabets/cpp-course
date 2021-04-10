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

bool Tablet::isStylus() const
{
	return this->stylus;
}

void Tablet::setStylus(bool stylus)
{
	this->stylus = stylus;
}

istream& operator>>(istream& in, Tablet& obj)
{
	in >> dynamic_cast<Portative&>(obj);

	cout << "Has it stylus? (0 - No, 1 - Yes): ";
	in >> obj.stylus;

	return in;
}

ostream& operator<<(ostream& os, Tablet& obj)
{
	cout << boolalpha;
	return os << dynamic_cast<Portative&>(obj) << setw(10) << obj.stylus << endl;
}

fstream& operator<<(fstream& out, Tablet& obj)
{
	out << dynamic_cast<Portative&>(obj);
	out << obj.stylus << '\n';
	return out;
}

fstream& operator>>(fstream& in, Tablet& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	in >> obj.stylus;
	in.clear();
	in.ignore(10000, '\n');
	return in;
}

ofstream& operator<<(ofstream& out, Tablet& obj)
{
	out << dynamic_cast<Portative&>(obj);
	out.write(reinterpret_cast<char*>(&obj.stylus), sizeof(obj.stylus));
	return out;
}

ifstream& operator>>(ifstream& in, Tablet& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	in.read(reinterpret_cast<char*>(&obj.stylus), sizeof(obj.stylus));
	return in;
}
