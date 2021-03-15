/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/


#include "Trim.h"
namespace sdds {

	void Trim(std::string* array, int size, std::string& src)
	{
		for (int i = 0; i < size - 1; i++) {
			int firstComma;
			firstComma = src.find(",");
			array[i] = src.substr(0, firstComma);
			array[i].erase(0, array[i].find_first_not_of(" "));
			array[i].erase(array[i].find_last_not_of(" ") + 1, array[i].length());
			src.erase(0, firstComma + 1);
		}

	};







}