// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-11-20
*/


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	//loop through the 2 Lists to compare and use the paired desc and price to create new Product then add to the priceList list 
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product* temp = nullptr;
		for (size_t i = 0u; i < desc.size(); ++i) {
			for (size_t o = 0u; o < price.size(); o++) {
				if (desc[i].code == price[o].code) {
					temp = new Product(desc[i].desc, price[o].price);
					temp->validate();
					priceList += temp;
					delete temp;
					temp = nullptr;
				
				}		
			}
		}

		return priceList;
	}
	//use smart pointers
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0u; i < desc.size(); ++i) {
			for (size_t o = 0u; o < price.size(); o++) {
				if (desc[i].code == price[o].code) {

					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[o].price));

					temp->validate();
					priceList += (temp);
					temp = nullptr;
				}
			}
		}
		return priceList;
	}
}