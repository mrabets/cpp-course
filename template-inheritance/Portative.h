#pragma once
#include "VMachine.h"
class Portative : public VMachine
{
public:
	Portative();
	Portative(int battery, string model);
	Portative(const Portative& object);
	~Portative();

	int getBattery();
	void setBattery(int battery);

protected:
	int battery;
};

