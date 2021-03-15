// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-13
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H
#include "Utilities.h"

class Station
{
	size_t m_station_id = 0;
	std::string m_item_name = "";
	std::string m_description = "";
	size_t m_serial_number = 0;
	size_t m_amount_left = 0;
	static size_t m_widthField;
	static size_t id_generator;
public:
	Station() {}
	Station(const std::string& str);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif