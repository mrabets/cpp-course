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
	friend ostream& operator << (ostream& os, Stationary& obj);

private:
	double powerSupply;
};
