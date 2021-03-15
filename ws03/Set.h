/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-10
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <string>
#include <iostream>
#include <iomanip>
namespace sdds {
	template<typename T, unsigned int N>
	class Set {
		T collection[N];
		unsigned int numOfcollection = 0;
	public:
		size_t size() const {
			return numOfcollection;
		}

		const T& operator[](size_t idx) const {
			if (idx >= 0 && static_cast<unsigned int>(idx) < numOfcollection) {
				return collection[idx];
			}
			else {
				std::cout << "index beyond the range!!!";
				return  collection[numOfcollection];
			}
		}

		 void operator+=(const T& item) {
			if (numOfcollection < (N)) {
				collection[numOfcollection] = item;
				++numOfcollection;
			}
		}
	};
}
#endif