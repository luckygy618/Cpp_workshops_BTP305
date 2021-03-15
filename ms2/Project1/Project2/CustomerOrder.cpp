// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
size_t CustomerOrder::m_widthField = 0;
CustomerOrder::CustomerOrder(std::string& str)
{
	Utilities extractor;
	std::string strcpy = "";
	std::string holderstr = "";
	bool more = true;
	size_t next_pos = 0;
	size_t counter_pos = 0;
	int counter = 0;
	holderstr = extractor.extractToken(str, next_pos, more);
	if (more == true) {
		m_name = holderstr;
	}
	holderstr = extractor.extractToken(str, next_pos, more);
	if (more == true) {
		m_product = holderstr;
	}
	counter_pos = next_pos;
	while (counter_pos > 0 && more == true) {
		holderstr = extractor.extractToken(str, counter_pos, more);
		counter++;
	}
	holderstr = "";
	m_lstItem = new Item * [counter];
	counter = 0;
	more = true;
	while (next_pos > 0 && more == true) {
		holderstr = extractor.extractToken(str, next_pos, more);
		m_lstItem[counter] = new Item(holderstr);
		counter++;
		m_cntItem++;
	}

	
	if (m_widthField < extractor.getFieldWidth()) {
		m_widthField = extractor.getFieldWidth(); 
	}
}

CustomerOrder::~CustomerOrder()
{
	deleteItem();
}

void CustomerOrder::setEmpty()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
}

void CustomerOrder::deleteItem()
{
	if (m_lstItem != nullptr ||m_cntItem>0) {
		for (size_t i = 0; i < m_cntItem; i++) {
			
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			
		}
		delete [] m_lstItem;
	}
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const CustomerOrder& cpy)
{
	try {
		throw("----> ERROR: Cannot make copies.\n");
	}
	catch (const char* err) {
		std::cout << err << std::endl;
	}
}

CustomerOrder::CustomerOrder(CustomerOrder&& mv) noexcept
{
	*this = std::move(mv);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& mv) noexcept
{
	if (this != &mv) {
		m_name = mv.m_name;
		m_product = mv.m_product;
	
		 deleteItem();
		 m_lstItem = mv.m_lstItem;
		 m_cntItem = mv.m_cntItem;
		 mv.setEmpty();
		 mv.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isOrderFilled() const
{
	int ii = 0;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled==false) {
			ii++;
		}
	}
	if (ii > 0) { return false; }
	else { return true; }
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{
	int ii = -1;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			ii = i;
		}
	}
	if (ii >= 0) {
		return m_lstItem[ii]->m_isFilled;
	}
	else { return true; }
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	int ii = -1;
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			ii = i;
		}
	}
	if (ii>=0) {
		if (station.getQuantity() > 0) {
			station.updateQuantity();
					m_lstItem[ii]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[ii]->m_isFilled = true;
					os << "    "<<"Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
		}
		else {
			os <<"    "<< "Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++) {
	
		os << "[";
		os << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << std::setfill(' ');
		os << "] ";
		os << std::setw(m_widthField) << m_lstItem[i]->m_itemName;
		os <<"    "<< " - ";
		os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING");
		os << std::endl;
	}
}


