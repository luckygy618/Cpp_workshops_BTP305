/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#ifndef SDDS_UTILITY_H
#define SDDS_UTILITY_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <list>
#include <utility>
#include <sstream>
#include "Vehicle.h"

namespace sdds {
	extern const int numOfstrings;

	Vehicle* createInstance(std::istream& in);

	//trim the array from input
	void Trim(int size, std::string& src, std::string* arrayOftrimed);

	//trim the whitespace from the string
	void TrimWhiteSpace(std::string& src);
}
#endif