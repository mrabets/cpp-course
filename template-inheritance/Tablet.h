#pragma once
#include "Portative.h"
class Tablet : public Portative
{
public:
	Tablet();
	Tablet(bool stylus, int battery, string model);
	Tablet(const Tablet& object);
	~Tablet();

	bool isStylus() const;
	void setStylus(bool stylus);

	friend istream& operator >> (istream& in, Tablet& obj);
	friend ostream& operator << (ostream& os, Tablet& obj);

private:
	bool stylus;
};
