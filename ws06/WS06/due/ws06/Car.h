/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car() {
			m_maker = "";
			m_condition = "";
			m_topSpeed = 0.00;
		}

		Car(std::istream& in);
		void setEmpty();
		bool isEmpty() const;

		std::string condition() const;
		double topSpeed() const;

		void display(std::ostream& os) const;

		void setup(std::istream& in);
	};
}
#endif
