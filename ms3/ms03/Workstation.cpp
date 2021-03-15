// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"
//constructor that set the object to empty status
Workstation::Workstation(const std::string str) :Station(str)
{
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os)
{
	if (m_orders.size() > 0) {//check if there is at least 1 item exist
		if (m_orders.front().isItemFilled(getItemName()) == false) {
			m_orders.front().fillItem(*this, os);//fill the item
		}
	}
}

bool Workstation::moveOrder()
{
	bool result = false;
	if (m_orders.size() > 0) {
		if (m_orders.front().isItemFilled(getItemName()) == true) { //if the order in m_orders is filled
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());//move this filled order to next workstation
				m_orders.pop_front(); //delete the removed order from the current m_orders
				result = true;
			}
		}
	}
	return result;
}

Workstation& Workstation::operator+=(CustomerOrder&& mv)
{
	m_orders.push_back(std::move(mv)); //add an order to  m_orders
	return *this;
}

void Workstation::setNextStation(Station& station)
{
	m_pNextStation = static_cast<Workstation*>(&station);//use m_pNextStation to point a Workstation as the next workstation
}

const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation; // return the m_pNextStation
}

bool Workstation::getIfCompleted(CustomerOrder& order)
{
	bool result = false;
	if (m_orders.size() != 0) { //if there's order in m_orders
		if (m_orders.front().isOrderFilled() == true) { //if the first order is filled already
			order = std::move(m_orders.front()); //move it to the parameter to hold it and push it to the Completed container later
			m_orders.pop_front();  //delete the removed order
			result = true;
		}
	}

	return result;
}

//display current item in the current workstation and the next item name in the next workstation
void Workstation::display(std::ostream& os) const
{
	os << this->getItemName() << " --> ";
	if (m_pNextStation == nullptr) {
		os << "END OF LINE" << endl;
	}
	else {
		os << m_pNextStation->getItemName() << endl;
	}
}