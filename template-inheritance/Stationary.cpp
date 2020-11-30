#include "Stationary.h"

Stationary::Stationary()
{
	this->powerSupply = 0;
}

Stationary::Stationary(int powerSupply, string model) : VMachine(model)
{
	this->powerSupply = powerSupply;
}

Stationary::Stationary(const Stationary& object) : VMachine(object)
{
	this->powerSupply = object.powerSupply;
}

Stationary::~Stationary()
{
}

int Stationary::getPowerSupply()
{
	return this->powerSupply;
}

void Stationary::setPowerSupply(int powerSupply)
{
	this->powerSupply = powerSupply;
}