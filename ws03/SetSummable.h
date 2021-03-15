/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-10
*/

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {
	template<typename T, unsigned int N>
	class SetSummable : public Set<T, N> {  //inherit fron Set, but Set is a templete class too. So should use Set<T,N>
	public:
		T accumulate(const std::string& filter) const;
	};



	template<typename T, unsigned int N>
	inline T SetSummable<T, N>::accumulate(const std::string& filter) const
	{
		T localt(filter);  //create a T type object to hold the sum
		for (unsigned int i = 0; i < (*this).size(); i++) {
			localt += (*this).operator[](i);		//call the operator [] to return the element in the array
		}
		return localt;			//return the object for later show it on screen
	}
}

#endif
