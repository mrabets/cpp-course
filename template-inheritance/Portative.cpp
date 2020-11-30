#include "Portative.h"

Portative::Portative() : VMachine()
{
    this->battery = 0;
}

Portative::Portative(int battery, string model) : VMachine(model)
{
    this->battery = battery;
}

Portative::Portative(const Portative& object) : VMachine(object)
{
    this->battery = object.battery;
}

Portative::~Portative()
{
}

int Portative::getBattery()
{
    return this->battery;
}

void Portative::setBattery(int battery)
{
    this->battery = battery;
}