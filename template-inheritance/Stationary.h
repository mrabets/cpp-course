#include "VMachine.h"
class Stationary : public VMachine
{
public:
	Stationary();
	Stationary(int powerSupply, string model);
	Stationary(const Stationary& object);
	~Stationary();

	int getPowerSupply();
	void setPowerSupply(int powerSupply);

protected:
	int powerSupply;
};
