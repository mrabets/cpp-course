#pragma once

#include "BaseException.h"

constexpr auto LENGTH = 40;

class VMachine
{
public:
	VMachine();
	VMachine(string model);
	VMachine(const VMachine& object);
	~VMachine();

	string getModel() const;
	void setModel(string model);

	friend istream& operator >> (istream& in, VMachine& obj);
	friend ostream& operator << (ostream& os, const VMachine& obj);

	friend fstream& operator<<(fstream& out, VMachine& obj);
	friend fstream& operator>>(fstream& in, VMachine& obj);

	friend ofstream& operator<<(ofstream& out, VMachine& obj);
	friend ifstream& operator>>(ifstream& in, VMachine& obj);

	virtual void write(std::ostream& f);
	virtual void read(std::istream& f);
protected:
	string model;
};