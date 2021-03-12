#pragma once

#include "BaseException.h"

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
	friend ostream& operator << (ostream& os, VMachine& obj);

	friend ifstream& operator >> (ifstream& in, VMachine& obj);
	friend ofstream& operator << (ofstream& out, VMachine& obj);

private:
	string model;
};