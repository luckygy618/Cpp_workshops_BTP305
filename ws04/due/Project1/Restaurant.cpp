/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#include "Restaurant.h"
namespace sdds {
	sdds::Restaurant::Restaurant(Reservation* reservations[], size_t cnt) //constructor
	{
		numOfres = cnt;
		resArray = new Reservation[numOfres];
		for (size_t i = 0; i < numOfres; i++) {
			addres(resArray[i], *reservations[i]);
		}
	}

	Restaurant& Restaurant::operator=(const Restaurant& cpy) //copy operator
	{
		if (this != &cpy && cpy.isEmpty() != true) {
			if (!this->isEmpty()) { SetEmpty(); }
			this->numOfres = cpy.numOfres;
			this->resArray = new Reservation[numOfres];
			for (size_t i = 0; i < numOfres; i++) {
				addres(resArray[i], cpy.resArray[i]);
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) //move operator that takes a rvalue 
	{
		try {
			if (this != &src && src.isEmpty() != true) {
				if (this->resArray != nullptr) { SetEmpty(); }
				this->numOfres = src.numOfres;
				this->resArray = src.resArray;
				src.resArray = nullptr;
			}
			return *this;

		}
		catch (std::exception& e) {
			std::cout << " Exception ERR" << std::endl;
		}
	}

	Restaurant::~Restaurant() //destructor
	{
		SetEmpty();
	}

	void sdds::Restaurant::SetEmpty() //set object to empty
	{
		if (resArray != nullptr) {
			delete[] resArray;
			resArray = nullptr;
		}
		numOfres = 0;
	}

	bool Restaurant::isEmpty() const //return empty  status of object
	{
		if (resArray == nullptr || numOfres == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Reservation& Restaurant::addres(Reservation& ori, const Reservation& cpy) //copy the Reservation object
	{
		ori = cpy;
		return ori;
	}

	size_t Restaurant::size() const //return the numOfres 
	{
		return numOfres;
	}


	std::ostream& operator<<(std::ostream& os, const Restaurant& rest) //display the object
	{
		

			os << "--------------------------" << std::endl << "Fancy Restaurant" << std::endl
				<< "--------------------------" << std::endl;
			if (rest.isEmpty()) {
				os << "The object is empty!" << std::endl << "--------------------------" << std::endl;
			}
			else {
				for (size_t i = 0; i < rest.size(); i++) {
					os << rest.resArray[i];
				}
				os << "--------------------------" << std::endl;
			}
		
		return os;
	}
}