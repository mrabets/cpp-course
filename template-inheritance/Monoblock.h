#pragma once
#include "Stationary.h"
class Monoblock : public Stationary
{
public:
	Monoblock();
	Monoblock(string standColour, int powerSupply, string model);
	Monoblock(const Monoblock& object);
	~Monoblock();

	string getStandColour() const;
	static int getCount();
	void setStandColour(string standColour);

	friend istream& operator >> (istream& in, Monoblock& obj);
	friend ostream& operator << (ostream& os, Monoblock& obj);

private:
	string standColour;
	static int count;
};

int Monoblock::count = 0;
