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

string VMachine::getModel()
{
	return this->model;
}

void VMachine::setModel(string model)
{
	this->model = model;
}