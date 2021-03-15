// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		int iii = 0, skip=0;
		std::ifstream load(argv[1]);
		if (!load)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 3;
		}
		while (!load.eof()&&iii<7){
			skip++;
			std::string temp="";
			getline(load, temp);
			if (skip > 2) {
				library[iii] = Book(temp);
				iii++;
			}
			temp = "";
		}
		load.close();
		iii = 0;
		skip=0;
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	
	auto fun = [=, &library]() {
		for (int i = 0; i < 7; i++) {
			if (library[i].country() == "US") {
				library[i].price() *= usdToCadRate;
			}

			if (library[i].country() == "UK" && (static_cast<int>(library[i].year()) >= 1990 && static_cast<int>(library[i].year()) <= 1999)) {
				library[i].price() *= gbpToCadRate;
			}
		}
	};

	
	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.

	fun();
	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& book : library)
		std::cout << book;
	std::cout << "-----------------------------------------\n";

	return 0;
}
