#include "VMachine.h"
class Stationary : public VMachine
{
public:
	Stationary();
	Stationary(int powerSupply, string model);
	Stationary(const Stationary& object);
	~Stationary();

	int getPowerSupply() const;
	void setPowerSupply(int powerSupply);

	friend istream& operator >> (istream& in, Stationary& obj);
	friend ostream& operator << (ostream& os, Stationary& obj);

private:
	int powerSupply;
};
