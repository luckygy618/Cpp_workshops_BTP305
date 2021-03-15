/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender
	{
		Reservation** resPtrArray = nullptr;
		size_t numOfresPtr = 0;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cpy) { *this = cpy; }
		ConfirmationSender(ConfirmationSender&& src) { *this = std::move(src); }
		ConfirmationSender& operator=(const ConfirmationSender& cpy);
		ConfirmationSender& operator=(ConfirmationSender&& cpy);
		void setEmpty();
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmation);
	};

}
#endif
