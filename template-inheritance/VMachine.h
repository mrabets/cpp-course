#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class VMachine
{
public:
	VMachine();
	VMachine(string model);
	VMachine(const VMachine& object);
	~VMachine();

	string getModel();
	void setModel(string model);

protected:
	string model;
};

