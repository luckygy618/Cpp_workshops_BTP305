#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Car.h"
#include "Utilities.h"
namespace sdds {



	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop() {}
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

	};

}

#endif