#pragma once
#include "VMachine.h"
class Portative : public VMachine
{
public:
	Portative();
	Portative(int battery, string model);
	Portative(const Portative& object);
	~Portative();

	int getBattery() const;
	void setBattery(int battery);

	friend istream& operator >> (istream& in, Portative& obj);
	friend ostream& operator << (ostream& os, Portative& obj);

	friend ifstream operator >> (ifstream& in, Portative& obj);
	friend ofstream operator << (ofstream& out, Portative& obj);

private:
	int battery;
};

