/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Vehicle.h"
#include "Car.h"
#include "Utilities.h"
namespace sdds {
	class Racecar : public Car
	{
		double m_booster = 0.00;
	public:

		Racecar() : Car() { m_booster = 0.00; }
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif