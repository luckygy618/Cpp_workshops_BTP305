/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/


#include "Book.h"
namespace sdds {
	//defualt constructor
	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.00;
		m_description = "";
	}

	//get title
	const std::string& Book::title() const
	{
		return this->m_title;
	}

	//get country
	const std::string& Book::country() const
	{
		return m_country;
	}

	//get year
	const size_t& Book::year() const {
		return m_year;
	}

	//get price. it returns a reference so that it can be changed 
	double& Book::price()
	{
		return m_price;
	}

	//constructor that read the string and cut the string into 6 parts
	Book::Book(const std::string& strBook) {
		if (strBook.length() > 0) {
			std::string holderArray[6] = { "","","","","","" };
			std::string str = strBook;
			sdds::Trim(holderArray, 6, str);
			str.erase(0, str.find_first_not_of(" "));
			str.erase(str.find_last_not_of(" ") + 1, str.length());
			holderArray[5] = str;
			m_author = holderArray[0];
			m_title = holderArray[1];
			m_country = holderArray[2];
			m_price = std::stod(holderArray[3]);
			m_year = std::stoi(holderArray[4]);
			m_description = holderArray[5];
		}
	}

	//display the object
	std::ostream& operator << (std::ostream& os, const Book& book) {
		os << std::setw(20) << std::right << book.m_author << " | " << std::setw(22) << std::right << book.m_title << " | " << std::setw(5) << std::right << book.m_country
			<< " | " << std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::right << std::fixed << std::setprecision(2) << book.m_price << " | " << std::left << std::right << book.m_description << std::endl;
		return os;
	}

}