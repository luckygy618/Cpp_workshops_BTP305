// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include "Utilities.h"
#include "Station.h"
struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};


class CustomerOrder
{
	std::string m_name = "";
	std::string m_product = "";
	unsigned int m_cntItem = 0;
	//std::vector<Item*> m_lstItem;
	Item** m_lstItem=nullptr;
	static size_t m_widthField;

public:
	CustomerOrder() {}
	CustomerOrder(std::string& str);
	~CustomerOrder();
	void setEmpty();
	void deleteItem();
	CustomerOrder& operator=(const CustomerOrder& cpy) = delete;
	CustomerOrder(const CustomerOrder& cpy);
	CustomerOrder(CustomerOrder&& mv) noexcept;//This constructor should "promise" that it doesn't throw exceptions. Use the noexcept keyword in the prototype.
	CustomerOrder& operator= ( CustomerOrder&& mv) noexcept;
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif