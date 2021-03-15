/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/

#ifndef SDDS_MOVIE_H
#define  SDDS_MOVIE_H
#include<iomanip>
#include "SpellChecker.h"
namespace sdds {
	class Movie
	{
		std::string m_title;
		size_t  m_year;
		std::string m_description;
	public:
		Movie() :m_title{ "" }, m_year{ 0 }, m_description{ "" }{}
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		template<typename T>
		void fixSpelling(T spellChecker, std::string& strr) {
			spellChecker(strr);
		}

		friend std::ostream& operator << (std::ostream& os, const Movie& movie);

	};

}
#endif