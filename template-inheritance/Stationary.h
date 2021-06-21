
#include "VMachine.h"
class Stationary : public VMachine
{
public:
	Stationary();
	Stationary(double powerSupply, string model);
	Stationary(const Stationary& object);
	~Stationary();

	double getPowerSupply() const;
	void setPowerSupply(double powerSupply);

	friend istream& operator >> (istream& in, Stationary& obj);
	friend ostream& operator << (ostream& os, const Stationary& obj);

	friend fstream& operator<<(fstream& out, Stationary& obj);
	friend fstream& operator>>(fstream& in, Stationary& obj);

	friend ofstream& operator<<(ofstream& out, Stationary& obj);
	friend ifstream& operator>>(ifstream& in, Stationary& obj);
protected:
	double powerSupply;
};
