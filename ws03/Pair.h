/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-10
*/


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <string>
#include <iostream>
#include <iomanip>
namespace sdds {

	template<typename K, typename V>
	class Pair {
		K pkey;
		V pvalue;

	public:
		Pair() : pkey{}, pvalue{}{}       //must have this default constructor. because K and V is not known, use this way to initialize 
										
		Pair(const K& cpyKey, const V& cpyValue) {
			pkey = cpyKey;
			pvalue = cpyValue;
		}

		const K& key() const { return pkey; }
		const V& value() const { return pvalue; }
		virtual void display(std::ostream& os) const;

	};


	template<typename K, typename V>												//it is not a member fuction of Pair
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {		// so it does not need "Pair<K,V>::"
		pair.display(os);
		return os;
	}

	template<typename K, typename V>
	void Pair<K,V>::display(std::ostream& os) const {
		os << pkey << " : " << pvalue << std::endl;
	}
}
#endif