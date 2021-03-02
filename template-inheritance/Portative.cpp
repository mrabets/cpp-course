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

int Portative::getBattery() const
{
    return this->battery;
}

void Portative::setBattery(int battery)
{
    this->battery = battery;
}

istream& operator>>(istream& in, Portative& obj)
{
    in >> dynamic_cast<VMachine&>(obj);

    obj.battery = GetCorrectNumber<int>(in, "Enter battery mAh value (ex. 1700): ", 1500, 100000);

    return in;
}

ostream& operator<<(ostream& os, Portative& obj)
{
    return os << dynamic_cast<VMachine&>(obj) << setw(10) << obj.battery;
}
