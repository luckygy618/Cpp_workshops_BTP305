#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
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

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {

			for (auto& i : m_vehicles)
				if (test(i))
					vehicles.push_back(i);
		}





	};

}

#endif