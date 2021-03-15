/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {
	
	class Book
	{
		std::string m_author="";
		std::string m_title="";
		std::string m_country="";
		size_t m_year=0;
		double m_price=0.00;
		std::string m_description="";

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator << (std::ostream& os, const Book& book);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_description);
		}
		
		template<typename T>
		void fixSpelling(T spellChecker,std::string& strrrrr) {
			spellChecker(strrrrr);
		}


		
	};

	

}
#endif