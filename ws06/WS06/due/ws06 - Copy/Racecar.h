#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Vehicle.h"
#include "Car.h"
#include "Utilities.h"
namespace sdds {

	class Racecar : public Car
	{
		double m_booster=0.00;
	public:
		
		Racecar() : Car() { m_booster = 0.00; }
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};


}
#endif