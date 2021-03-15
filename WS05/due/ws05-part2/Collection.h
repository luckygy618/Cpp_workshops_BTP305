/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <stdexcept>
namespace sdds {
	template<typename T>
	class Collection
	{
		T* m_arrayT = nullptr;
		std::string m_name = "";
		size_t m_size = 0;
		void (*fp)(const Collection<T>&, const T&);
	public:
		//defualt constructor
		Collection() {
			m_name = "initial_in_blank";
			m_arrayT = nullptr;
			m_size = 0u;
			fp = nullptr;
		}

		//constructor
		Collection(std::string name) {
			m_arrayT = nullptr;
			m_name = name;
			m_size = 0;
			fp = nullptr;
		}

		//get the size
		size_t size() const { return m_size; }

		//delete copy = operator
		Collection& operator = (const Collection& cpy) = delete;

		//delete copy constructor
		Collection(const Collection& cpy) = delete;

		//destructor
		~Collection() {
			if (m_arrayT != nullptr) {
				delete[] m_arrayT;
				m_arrayT = nullptr;
			}
			m_size = 0;
			m_name = "";
		}

		//get name
		const std::string& name() const { return m_name; }

		//set the parameter to function pointer fp
		void setObserver(void (*observer)(const Collection<T>& collecotion, const T& items)) {
			fp = observer;
		}

		//overload += to add new item and resize the array
		Collection<T>& operator+=(const T& item) {
			if (item.title() != "" || item.title().length() > 0) {
				bool no_repeat = true;
				for (size_t i = 0u; i < m_size; i++) {
					if (m_arrayT[i].title() == item.title()) {
						no_repeat = false;
					}
				}

				if (no_repeat == true) {
					if (m_arrayT == nullptr) {
						m_arrayT = new T[1];
						m_arrayT[0] = item;
						m_size = 1;
					}
					else {
						T* temp = nullptr;
						temp = new T[m_size + 1];

						for (size_t i = 0u; i < m_size; i++) {
							temp[i] = m_arrayT[i];
						}
						temp[m_size] = item;
						m_size += 1;
						delete[] m_arrayT;
						m_arrayT = temp;
						temp = nullptr;
					}

					if (fp != nullptr) {
						fp(*this, item);
					}
				}
			}
			return *this;
		}


		//overload [] to get the members inside array
		T& operator[](size_t idx) const {
			if (idx >= m_size) {

				std::string errmessage = "";
				errmessage = "Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(errmessage);
			}
			return m_arrayT[idx];
		}

		//overload [] to get the members inside array
		T* operator[](std::string title) const {
			bool found = false;
			int idex = -999;
			T* ptr = nullptr;
			for (size_t i = 0u; i < m_size; i++) {
				if (m_arrayT[i].title() == title) {
					found = true;
					idex = i;
				}
			}

			if (found == true) {
				ptr = &m_arrayT[idex];
			}
			else { ptr = nullptr; }
			return ptr;
		}

		//friedn function to display the object
		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
			for (size_t i = 0u; i < collection.m_size; i++) {
				os << collection.m_arrayT[i];
			}
			return os;
		}
	};



}
#endif
