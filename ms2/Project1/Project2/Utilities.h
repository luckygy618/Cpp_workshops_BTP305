// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-13
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//namespace sdds {
class Utilities
{
	size_t m_widthField = 1;
	static std::string m_delimiter;//A class variable lasts the lifetime of the program and holds a value that all instances of the class share.
									//it has only 1 piece of memoery and used by all the class's objects

public:
	Utilities() {}
	Utilities(size_t width, const std::string delimeter) {
		m_widthField = width;
		m_delimiter = delimeter;
	}
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

//}
#endif