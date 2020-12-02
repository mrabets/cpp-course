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

istream& operator>>(istream& in, VMachine& obj)
{
	cout << "Enter model name (ex. Samsung): ";
	return in >> obj.model;
}

ostream& operator<<(ostream& os, VMachine& obj)
{
	return os << setw(10) << obj.model;
}
