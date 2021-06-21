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

void Laptop::write(std::ostream& f)
{
	Portative::write(f);
	size_t size = matrix.size();
	f.write((char*)&size, sizeof(size_t));
	f.write((char*)matrix.c_str(), size);
}

void Laptop::read(std::istream& f)
{
	Portative::read(f);

	size_t size;
	char* data;

	f.read((char*)&size, sizeof(size));
	data = new char[size + 1];
	f.read(data, size);
	data[size] = '\0';
	matrix = data;
	delete data;
}



bool operator<(const Laptop& first, const Laptop& second)
{
	if (first.model == second.model)
	{
		if (first.battery == second.battery)
		{
			return first.matrix < second.matrix;
		}

		return first.battery < second.battery;
	}
	return first.model < second.model;
}

bool operator==(const Laptop& first, const Laptop& second)
{
	return first.model == second.model &&
		   first.battery == second.battery &&
		   first.matrix == second.matrix;
}

istream& operator>>(istream& in, Laptop& obj)
{	
	in >> dynamic_cast<Portative&>(obj);
	obj.matrix = GetCorrectString(in, "Enter matrix name (ex. IPS): ", 10);
	return in;
}

ostream& operator<<(ostream& os, const Laptop& obj)
{
	return os << dynamic_cast<const Portative&>(obj) << setw(10) << obj.matrix << endl;
}


fstream& operator<<(fstream& out, Laptop& obj)
{
	out << dynamic_cast<Portative&>(obj);
	out << obj.matrix << '\n';
	return out;
}

fstream& operator>>(fstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	getline(in, obj.matrix, '\n');
	return in;
}

ofstream& operator<<(ofstream& out, Laptop& obj)
{
	out << dynamic_cast<Portative&>(obj);

	char buffer[LENGTH];

	strcpy_s(buffer, obj.matrix.length() + 1, obj.matrix.c_str());
	out.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));

	return out;
}

ifstream& operator>>(ifstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	
	char buffer[LENGTH];

	in.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
	string temp = string(buffer);
	obj.matrix = temp;

	return in;
}




















//fstream& operator<< (fstream& out, const Laptop& obj) {
//	out.write(reinterpret_cast<const char*>(&obj), sizeof(obj)); // И никто больше не ругается.
//	return out;
//}
