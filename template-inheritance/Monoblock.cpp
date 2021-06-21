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

bool operator<(const Monoblock& first, const Monoblock& second)
{
	return first.model < second.model;
}

bool operator==(const Monoblock& first, const Monoblock& second)
{
	return first.model == second.model
		&& first.powerSupply == second.powerSupply
		&& first.standColour == second.standColour;
}

istream& operator>>(istream& in, Monoblock& obj)
{
	in >> dynamic_cast<Stationary&>(obj);

	obj.standColour = GetCorrectString(in, "Enter stand colour (ex. Green): ", 15);

	return in;
}

ostream& operator<<(ostream& os, const Monoblock& obj)
{
	return os << dynamic_cast<const Stationary&>(obj) << setw(10) << obj.standColour << endl;
}

fstream& operator<<(fstream& out, Monoblock& obj)
{
	out << dynamic_cast<Stationary&>(obj);
	out << obj.standColour << '\n';
	return out;
}

fstream& operator>>(fstream& in, Monoblock& obj)
{
	in >> dynamic_cast<Stationary&>(obj);
	getline(in, obj.standColour, '\n');
	return in;
}

ofstream& operator<<(ofstream& out, Monoblock& obj)
{
	out << dynamic_cast<Stationary&>(obj);

	char buffer[LENGTH];

	strcpy_s(buffer, obj.standColour.length() + 1, obj.standColour.c_str());
	out.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	return out;
}

ifstream& operator>>(ifstream& in, Monoblock& obj)
{
	in >> dynamic_cast<Stationary&>(obj);

	char buffer[LENGTH];

	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string temp = string(buffer);
	obj.standColour = temp;

	return in;
}
