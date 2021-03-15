/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/


#include "Movie.h"
namespace sdds {
	//get title
	const std::string& Movie::title() const
	{
		return m_title;
	}

	//constructor
	Movie::Movie(const std::string& strMovie)
	{
		std::string holderArray[3] = { "","","" };
		std::string str = strMovie;
		sdds::Trim(holderArray, 3, str);
		holderArray[2] = str;
		holderArray[2].erase(0, holderArray[2].find_first_not_of(" "));
		holderArray[2].erase(holderArray[2].find_last_not_of(" ") + 1, holderArray[2].length());
		m_title = holderArray[0];
		m_year = std::stoi(holderArray[1]);
		m_description = holderArray[2];
	}

	//display the object
	std::ostream& operator << (std::ostream& os, const Movie& movie) {
		os << std::setw(40) << movie.m_title << " | " << std::setw(4) << movie.m_year << " | " << movie.m_description << std::endl;
		return os;

	}
}

