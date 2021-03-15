/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

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
		Autoshop() {} //defual constructor
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop(); //destructor

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) { //take any functor or lambda or functon 
			for (auto& i : m_vehicles) //loop the vehicles
				if (test(i))      //get the bool value from the parameter function
					vehicles.push_back(i); //add the vehicles object into the vector
		}
	};
}

#endif