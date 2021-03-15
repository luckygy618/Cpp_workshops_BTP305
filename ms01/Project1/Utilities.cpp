// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-13
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
using namespace std;
//define the static member 
std::string  Utilities::m_delimiter = ",";

//set the m_widthField
void  Utilities::setFieldWidth(size_t newWidth)
{
	m_widthField = newWidth;
}

//get the value of m_widthField
size_t  Utilities::getFieldWidth() const
{
	return m_widthField;
}

//extract 1 pieace per time from the string
std::string  Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	std::string holderString = "";
	size_t find_next_delimiter = 0u;
	more = false;
	try {
		if (next_pos < str.length()) {
			find_next_delimiter = str.find(m_delimiter, next_pos);//start from next_pos, find the next delimiter and return the positioin 
			if(find_next_delimiter != str.npos) {
				holderString = str.substr(next_pos, (find_next_delimiter- next_pos)); //extract the content between the delimiter and next_pos
				if (holderString.length() <= 0) {
					throw "No content between two delimiters";
				}
				else {
					next_pos = find_next_delimiter + 1;
					m_widthField = holderString.length();
					more = true;
				}
			}
			else {
				holderString = str.substr(next_pos);
				if (holderString.length() <= 0) {
					throw "No content between two delimiters";
				}
				else {
					more = true;
				}
			
			}

		}
		else {
			throw "m_widthField is larger than the string length";
		}
	}
	catch (const char* err) { cout << err << endl; }
	return holderString;
}

//set the delimiter
void  Utilities::setDelimiter(char newDelimiter)
{
	m_delimiter = newDelimiter;
}

//get the delimiter
char  Utilities::getDelimiter()
{
	return *m_delimiter.c_str();
}

