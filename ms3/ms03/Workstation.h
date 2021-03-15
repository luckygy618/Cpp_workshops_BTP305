// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

class Workstation : public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation = nullptr;
public:
	Workstation() :Station() {}
	Workstation(const std::string str);
	Workstation(const Workstation& cpy) = delete;
	Workstation& operator=(const Workstation& cpy) = delete;
	Workstation(const Workstation&& cpy) = delete;
	Workstation& operator=(const Workstation&& cpy) = delete;
	void runProcess(std::ostream&);
	bool moveOrder();
	Workstation& operator+=(CustomerOrder&&);
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
};

#endif