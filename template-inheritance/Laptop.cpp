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

fstream& operator>>(fstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	getline(in, obj.matrix, '\n');
	return in;
}

ofstream& operator<<(ofstream& out, Laptop& obj)
{
	out << dynamic_cast<Portative&>(obj);

	char buf[LENGTH];

	strcpy_s(buf, obj.matrix.length() + 1, obj.matrix.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	return out;
}

ifstream& operator>>(ifstream& in, Laptop& obj)
{
	in >> dynamic_cast<Portative&>(obj);
	
	char buf[LENGTH];

	in.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	string ss = string(buf);
	obj.matrix = ss;

	return in;
}




















//fstream& operator<< (fstream& out, const Laptop& obj) {
//	out.write(reinterpret_cast<const char*>(&obj), sizeof(obj)); // И никто больше не ругается.
//	return out;
//}
