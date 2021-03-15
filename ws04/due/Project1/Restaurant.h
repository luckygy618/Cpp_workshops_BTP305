/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* resArray=nullptr;
		size_t numOfres = 0;
	public:
		Restaurant() {
			resArray = nullptr;
			numOfres = 0;
		}
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& cpy) { *this = cpy; }
		Restaurant(Restaurant&& src) { *this = std::move(src); }
		Restaurant& operator=(const Restaurant& cpy);
		Restaurant& operator=(Restaurant&& src);
		~Restaurant();
		void SetEmpty();
		bool isEmpty() const;
		Reservation& addres(Reservation& ori, const Reservation& cpy);
		size_t size() const;
		friend 	std::ostream& operator<< (std::ostream& os, const Restaurant& rest);
	};
}

#endif
