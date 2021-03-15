/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#include "Autoshop.h"

sdds::Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)  //overload += to add theVehicle into the vector m_vehicles 
{
	if (theVehicle != nullptr) {
		m_vehicles.push_back(theVehicle);
	}
	return *this;
}

void sdds::Autoshop::display(std::ostream& os) const  //display the cars
{
	os << "--------------------------------" << std::endl;
	os << "| Cars in the autoshop!        |" << std::endl;
	os << "--------------------------------" << std::endl;

	for (unsigned int i = 0; i < m_vehicles.size(); i++) { //loop the vector
		if (nullptr != m_vehicles.at(i) && m_vehicles.at(i)->topSpeed() > 0) {
			m_vehicles.at(i)->display(os); //display the cars

			os << std::endl;
		}
	}
	os << "--------------------------------" << std::endl;
}

sdds::Autoshop::~Autoshop()  //destructor
{
	for (std::vector<Vehicle*>::iterator i = m_vehicles.begin(); i != m_vehicles.end(); i++) { //loop the vector by iterator
		if (NULL != *i) {
			delete* i;
			*i = NULL;
		}
	}
	m_vehicles.clear();
}