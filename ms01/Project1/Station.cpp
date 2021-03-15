// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-13
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
using namespace std;
//define the static members
size_t  Station::m_widthField = 0;
size_t  Station::id_generator = 0;

//constructor 
 Station::Station(const std::string& str)
{
	Utilities read_date;
	bool more = true;
	std::size_t cur_pos = 0;
	try {
		for (auto i = 0; i < 4; ++i) {
			if (more == true) {

				switch (i) {
				case 0: // 0 is a int, '0' is a const char that 
					m_item_name = read_date.extractToken(str, cur_pos, more); //extract from the string str
					break;
				case 1:
					m_serial_number = static_cast<size_t>(std::stoi(read_date.extractToken(str, cur_pos, more)));
					break;
				case 2:
					m_amount_left = static_cast<size_t>(std::stoi(read_date.extractToken(str, cur_pos, more)));
					break;
				case 3:
					m_description = read_date.extractToken(str, cur_pos, more);
					break;
				default:
					more = false;
				}
			}

			if (i < 3) {//update the fieldwidth 
				if (m_widthField < read_date.getFieldWidth()) {
					m_widthField = read_date.getFieldWidth();
				}
				else {
					m_widthField = m_widthField;
				}
			}
		}
		id_generator++;
		m_station_id = id_generator;
	}
	catch (std::exception& err) {
		cout << err.what() << std::endl;
	}
}

 //get the item name
const std::string&  Station::getItemName() const
{
	return m_item_name;
}

//get the serial number and then increase it by 1
unsigned int  Station::getNextSerialNumber()
{
	return m_serial_number++;
}

//get the quantity of the items left
unsigned int  Station::getQuantity() const
{
	return m_amount_left;
}

//update the amount of the rest items
void  Station::updateQuantity()
{
	try {
		if (m_amount_left >= 1) {
			m_amount_left -= 1;
		}
		else {
			throw "m_amount_left is less than 1 !";
		}
	}
	catch (const char* err) {
		cout << err<<endl;
	}

}

//display the station oobject to the screen
void  Station::display(std::ostream& os, bool full) const
{
	os << "[" << std::setw(3) << std::setfill('0')<<std::right << m_station_id << "]";
	os << " Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_item_name;
	os << " [" << std::setw(6) << std::setfill('0') <<std::right<< m_serial_number << "]";
	
	if (full == true) {
		os << " Quantity: " << std::setw(m_widthField)<< std::setfill(' ') << std::left << m_amount_left;
		os << std::left << " Description: " << m_description;
	}
	os << std::endl;
}

