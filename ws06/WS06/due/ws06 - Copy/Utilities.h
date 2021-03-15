#ifndef SDDS_UTILITY_H
#define SDDS_UTILITY_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <list>
#include <utility>
#include <sstream>
#include "Vehicle.h"

namespace sdds {
	extern const int numOfstrings;
	
	Vehicle* createInstance(std::istream& in);




	//trim the array from input
	void Trim(int size, std::string& src, std::string* arrayOftrimed);


	//trim the whitespace from the string
	void TrimWhiteSpace(std::string& src);
	


}
#endif