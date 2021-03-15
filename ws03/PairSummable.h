/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-10
*/

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iomanip>
#include <string>
#include "Pair.h"
namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair< K, V>
	{
		static  V initialValue; //static members must be declared inside class but defined outside class
		static  size_t width;  //static members must be declared inside class but defined outside class
							// So that compiler will not need to be ambiguious whether the first "=" inside the class' member fucntion is "initialization" or "assignment"
	public:
		PairSummable() {}; //it does nothing but needs to be exist
		PairSummable(const K& key, const V& value = initialValue) : Pair<K, V>(key, value) { // this constructor has default value, so that it does not have to 
																							 //has a value parameter. Then it will creates ambiguious issue with other 1 parameter constructors
			if (width < key.size()) {
				width = key.size();
			}
		}

		PairSummable<K, V>& operator+=(const PairSummable<K, V>& cpy) {
			if (this != &cpy && this->key() == cpy.key()) {
				*this = PairSummable(this->key(), this->value() + cpy.value());
			}
			return *this;
		}

		void display(std::ostream& os) const override { //override the virtual fuction of the base class
			os << std::setw(width) << std::left;
			Pair< K, V>::display(os);
			os << std::left;
		}
	};

	template<>
	PairSummable<std::string, int>& PairSummable<std::string, int>::  operator+=(const PairSummable& cpy) {
		if (this != &cpy && this->key() == cpy.key()) {
			*this = PairSummable(this->key(), this->value() + cpy.value());
		}
		return *this;
	}

	// return type                               templeted class name                   function name
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>:: operator += (const PairSummable& cpy) {
		if (this != &cpy && (*this).key() == cpy.key()) {
			if (this->value() == "") {
				*this = PairSummable(this->key(), this->value() + cpy.value()); //because key() and value() returned const value, so I cannot change them directely
																				//so I have to create a new object with the combined value and then return the new object  
			}
			else {
				*this = PairSummable(this->key(), this->value() + ", " + cpy.value());//because of the object  *this is static and no dynamic memory used
																					  // so just change the object and the previous memory will deleted automatically
			}
		}
		return *this;
	}


	//when string type passed in, the initialValue needs a memory address to hold the string, so it has to be initialized with "" empty sting
	template<>
	std::string PairSummable<std::string, std::string>::initialValue = ""; //this is the specialization of V type initialValue

	template<>
	int PairSummable<std::string, int>::initialValue = 0;// this is another specialization of V type initialValue

	template<typename K, typename V>
	size_t PairSummable<K, V>::width = 0; //this is not specialization, the width has its type size_t, but this definition of width has to 
	// put outside of the class, because width is a static member, a static member has to be define outside the class

	//this is the constructor, it does nothing but it has to be exist.
	
}
#endif
