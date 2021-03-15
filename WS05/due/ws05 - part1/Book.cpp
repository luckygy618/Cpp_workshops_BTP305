#include "Book.h"
namespace sdds {
	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.00;
		m_description = "";
	}

	const std::string& Book::title() const
	{
		return this->m_title;
	}

	const std::string& Book::country() const
	{
		return m_country; 
	}

	const size_t& Book::year() const { 
		return m_year;
	}

	double& Book::price()
	{
		return m_price; 
	}

	Book::Book(const std::string& strBook) {
		std::string holderArray[6] = { "","","","","","" };
		std::string str = strBook;

		for (int i = 0; i < 5; i++) {
			int firstComma;
			firstComma = str.find(",");
			holderArray[i] = str.substr(0, firstComma);
			holderArray[i].erase(0, holderArray[i].find_first_not_of(" "));
			holderArray[i].erase(holderArray[i].find_last_not_of(" ") + 1, holderArray[i].length());
			str.erase(0, firstComma + 1);
		}
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
 
	 std::ostream& operator << (std::ostream& os, const Book& book) {
		os << std::setw(20) << std::right << book.m_author << " | " << std::setw(22) << std::right << book.m_title << " | " << std::setw(5) << std::right << book.m_country
			<< " | " << std::setw(4) << book.m_year << " | "
			<< std::setw(6) << std::right << std::fixed << std::setprecision(2) << book.m_price << " | " << std::left << std::right << book.m_description << std::endl;

		return os;

	}

}