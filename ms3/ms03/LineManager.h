// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include "CustomerOrder.h"
#include "Workstation.h"
class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder = 0;
	Workstation* firstWorkStation = nullptr;

public:
	LineManager() {}
	LineManager(const std::string& FileName, std::vector<Workstation*>& AssemblyWorkstation, std::vector<CustomerOrder>& Customer_Order);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
};

#endif