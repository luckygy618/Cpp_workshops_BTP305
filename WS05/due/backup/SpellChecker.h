/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/



#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string> 
#include <fstream>
#include <iostream>
#include <sstream>
namespace sdds {
	class SpellChecker
	{
		 std::string m_badWords[5];
		 std::string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
		SpellChecker( std::string& str);
		SpellChecker() {}


	};




	void Trim(std::string* array, int size, std::string& src);

	void Trim(std::string& src);

}
#endif
