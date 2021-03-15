/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
namespace sdds {
	class Reservation
	{
		std::string reservationID;
		std::string name;
		std::string email;
		std::string food;
		size_t numOfpeople;
		size_t day;
		size_t hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		Reservation& operator=(const Reservation& cpy);
		Reservation(const Reservation& cpy);
		bool isEmpty() const;
		friend 	std::ostream& operator<< (std::ostream& os, const Reservation& res);
	};
}

#endif


