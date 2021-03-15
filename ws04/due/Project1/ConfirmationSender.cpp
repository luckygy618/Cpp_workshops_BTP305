/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#include "ConfirmationSender.h"
namespace sdds {
	sdds::ConfirmationSender::ConfirmationSender() //default constructor
	{
		resPtrArray = nullptr;
		numOfresPtr = 0;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cpy) // copy operator
	{
		setEmpty();
		this->numOfresPtr = cpy.numOfresPtr;
		resPtrArray = new Reservation * [numOfresPtr];
		for (size_t i = 0; i < numOfresPtr; i++) {
			resPtrArray[i] = cpy.resPtrArray[i];
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cpy) //move operator
	{
		try {
			setEmpty();
			this->numOfresPtr = cpy.numOfresPtr;
			this->resPtrArray = cpy.resPtrArray;
			cpy.resPtrArray = nullptr;
			return *this;
		}
		catch (std::exception& e) {
			std::cout << "Exception ERROR" << std::endl;
		}
	}


	sdds::ConfirmationSender::~ConfirmationSender() //destructor
	{
		setEmpty();
	}

	void sdds::ConfirmationSender::setEmpty() //set object to empty state
	{
		if (resPtrArray != nullptr) {
			delete[] resPtrArray;
		}
		numOfresPtr = 0;
		resPtrArray = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) //add a reservation
	{
		if (resPtrArray == nullptr && numOfresPtr == 0) {  //add directely when resPtrArray is empty
			resPtrArray = new Reservation * [1];
			resPtrArray[0] = const_cast<Reservation*>(&res);
			numOfresPtr++;
		}
		else {
			int existing = 0;
			for (size_t i = 0; i < numOfresPtr; i++) { //go over  the resPtrArray to see if the res is already existing
				if (this->resPtrArray != nullptr && this->resPtrArray[i] != nullptr) {
					if (this->resPtrArray[i] == const_cast<Reservation*>(&res)) {
						existing++;
					}
				}
			}

			if (existing == 0) { //if res is not existing
				size_t num = numOfresPtr + 1;
				Reservation** temp = nullptr;
				temp = new Reservation * [num];
				for (size_t i = 0; i < numOfresPtr; i++) {
					if (this->resPtrArray != nullptr && this->resPtrArray[i] != nullptr) {
						temp[i] = resPtrArray[i];   //copy the current resPtrArray
					}
				}
				temp[numOfresPtr] = const_cast<Reservation*>(&res); //append the adding res
				setEmpty();  //delete the current resPtrArray
				this->resPtrArray = temp;  //switch pointer
				temp = nullptr; 
				this->numOfresPtr = num;
			}
		}
		return *this;
	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) //delete a Reservation
	{
		for (size_t i = 0; i < numOfresPtr; i++) {
			if (resPtrArray[i] == const_cast<Reservation*>(&res)) {
				resPtrArray[i] = nullptr;
			}
		}
		return *this;
	}



	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmation)  //display the object
	{
		os << "--------------------------" << std::endl << "Confirmations to Send" << std::endl << "--------------------------" << std::endl;
		if (confirmation.resPtrArray == nullptr || confirmation.numOfresPtr == 0) {
			os << "The object is empty!" << std::endl << "--------------------------" << std::endl;
		}
		else {
			for (size_t i = 0; i < confirmation.numOfresPtr; i++) {
				if (confirmation.resPtrArray[i] != nullptr) {
					os << *confirmation.resPtrArray[i];
				}
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

}