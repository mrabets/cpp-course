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

	friend bool operator<(const Tablet& first, const Tablet& second);
	friend bool operator==(const Tablet& first, const Tablet& second);

	friend istream& operator >> (istream& in, Tablet& obj);
	friend ostream& operator << (ostream& os, const Tablet& obj);

	friend fstream& operator<<(fstream& out, Tablet& obj);
	friend fstream& operator>>(fstream& in, Tablet& obj);

	friend ofstream& operator<<(ofstream& out, Tablet& obj);
	friend ifstream& operator>>(ifstream& in, Tablet& obj);
private:
	bool stylus;
};
