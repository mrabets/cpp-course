#include "VMachine.h"

VMachine::VMachine()
{
	this->model = "empty";
}

VMachine::VMachine(string model)
{
	this->model = model;
}

VMachine::VMachine(const VMachine& object)
{
	this->model = object.model;
}

VMachine::~VMachine()
{

}

string VMachine::getModel() const
{
	return this->model;
}

void VMachine::setModel(string model)
{
	this->model = model;
}

void VMachine::write(std::ostream& f)
{
	size_t size = model.size();
	f.write((char*)&size, sizeof(size_t));
	f.write((char*)model.c_str(), size);
}

void VMachine::read(std::istream& f)
{
	size_t size;
	char* data;
	
	f.read((char*)&size, sizeof(size));
	data = new char[size + 1];
	f.read(data, size);
	data[size] = '\0';
	model = data;
	delete data;
}

istream& operator>>(istream& in, VMachine& obj)
{
	obj.model = GetCorrectString(in, "Enter model name (ex. Samsung): ", 20);
	return in;
}

ostream& operator<<(ostream& os, VMachine& obj)
{
	return os << setw(10) << obj.model;
}


fstream& operator<<(fstream& out, VMachine& obj)
{
	out << obj.model << ';' << " ";
	return out;
}

fstream& operator>>(fstream& in, VMachine& obj)
{
	getline(in, obj.model, ';');
	return in;
}

ofstream& operator<<(ofstream& out, VMachine& obj)
{
	/*out << obj.model << ';' << " ";
	return out;*/

	char buf[LENGTH];

	strcpy_s(buf, obj.model.length() + 1, obj.model.c_str());
	out.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	return out;
}

ifstream& operator>>(ifstream& in, VMachine& obj)
{
	/*getline(in, obj.model, ';');
	return in;*/

	char buf[LENGTH];

	in.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	string ss = string(buf);
	obj.model = ss;

	return in;
}

