#pragma once
#include "Portative.h"

class Laptop : public Portative
{
public:
	Laptop();
	Laptop(string matrix, int battery, string model);
	Laptop(const Laptop& object);
	~Laptop();

	string getMatrix() const;
	void setMatrix(string matrix);

	friend bool operator<(const Laptop& first, const Laptop& second);
	friend bool operator==(const Laptop& first, const Laptop& second);

	friend istream& operator>>(istream& in, Laptop& obj);
	friend ostream& operator<<(ostream& os, const Laptop& obj);

	friend fstream& operator<<(fstream& out, Laptop& obj);
	friend fstream& operator>>(fstream& in, Laptop& obj);

	friend ofstream& operator<<(ofstream& out, Laptop& obj);
	friend ifstream& operator>>(ifstream& in, Laptop& obj);

	void write(std::ostream& f) override;
	void read(std::istream& f) override;
private:
	string matrix;
};

