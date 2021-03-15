// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;


// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the book
	sdds::Collection<sdds::Book> library("Bestsellers");
	{

		int skip = 0;
		std::ifstream load(argv[1]);
		if (!load)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 3;
		}
		while (!load.eof() && skip < 4) {
			bool comment = false;
			std::string temp = "";
			getline(load, temp);
			if (temp.substr(0, 1) == "#") {
				comment = true;
			}


			if (comment == false && skip < 4) {
				library += Book(temp);
				skip++;

			}

			/*
			  if (comment == false && skip > 4) {
				  library += Book(temp);
				  skip++;
			  }
			  */
			temp = "";
		}
		//load.close();

		//skip = 0;

		// TODO: load the first 4 books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the collection "library" (use the += operator)
		//       - lines that start with "#" are considered comments and should be ignored


		library.setObserver(bookAddedObserver);

		// TODO: add the rest of the books from the file.

		while (!load.eof()) {
			bool comment = false;
			std::string temp = "";
			getline(load, temp);
			if (temp.substr(0, 1) == "#") {
				comment = true;
			}


			if (comment == false && skip >= 4) {
				library += Book(temp);
				skip++;

			}

			/*
			  if (comment == false && skip > 4) {
				  library += Book(temp);
				  skip++;
			  }
			  */
			temp = "";
		}


	}







	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;


	auto fun = [&](Book& book) {

		if (book.country() == "US") {
			book.price() *= usdToCadRate;
		}

		if (book.country() == "UK" && (static_cast<int>(book.year()) >= 1990 && static_cast<int>(book.year()) <= 1999)) {
			book.price() *= gbpToCadRate;
		}
	};
	// TODO: (from in-lab) create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	// TODO (from in-lab): iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (size_t i = 0u; i < library.size(); i++) {
		fun(library[i]);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	{
		std::ifstream loadmovie(argv[2]);
		if (!loadmovie)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 3;
		}
		int stored = 0;
		while (!loadmovie.eof() && stored < 5) {
			bool comment = false;
			std::string temp = "";
			getline(loadmovie, temp);
			if (temp.substr(0, 1) == "#") {
				comment = true;
			}

			if (comment == false) {
				movies[stored] = Movie(temp);
				stored++;
			}

			temp = "";
		}
		loadmovie.close();



	}





	// TODO: load 5 movies from the file "argv[2]".
	//       - read one line at a time, and pass it to the Movie constructor
	//       - store each movie read into the array "movies"
	//       - lines that start with "#" are considered comments and should be ignored


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	// Add a few movies to collection; no observer is set
	((theCollection += movies[0]) += movies[1]) += movies[2];
	theCollection += movies[1];
	// add more movies; now we get a callback from the collection
	theCollection.setObserver(movieAddedObserver);
	theCollection += movies[3];
	theCollection += movies[3];
	theCollection += movies[4];
	std::cout << "-----------------------------------------\n\n";

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";

	// TODO: The following loop can generate generate an exception
	//         write code to handle the exception
	//       If an exception occurs print a message in the following format
	//EXCEPTION: ERROR_MESSAGE<endl>
	//         where ERROR_MESSAGE is extracted from the exception object.
	try {
		for (auto i = 0u; i < 10; ++i) {
			std::cout << theCollection[i];
		}
	}
	catch (std::exception& error) {
		std::cout << "EXCEPTION: " << error.what() << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";


	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	for (auto i = 3u; i <= 4u; ++i)
	{
		// TODO: The following statement can generate generate an exception
		//         write code to handle the exception
		//       If an exception occurs print a message in the following format
		//EXCEPTION: ERROR_MESSAGE<endl>
		//         where ERROR_MESSAGE is extracted from the exception object.

		SpellChecker sp(argv[i]);
		try {
			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
			for (auto j = 0u; j < library.size(); ++j)
				library[j].fixSpelling(sp);

		}
		catch (std::exception& error) {
			std::cout << "EXCEPTION: " << error.what() << std::endl;
		}
	}
		std::cout << "--------------- Movies ------------------\n";
		std::cout << theCollection;
		std::cout << "--------------- Books -------------------\n";
		std::cout << library;
		std::cout << "-----------------------------------------\n\n";


		std::cout << "-----------------------------------------\n";
		std::cout << "Testing operator[] (the other overload)\n";
		std::cout << "-----------------------------------------\n";
		const Movie* aMovie = theCollection["Terminator 2"];
		if (aMovie == nullptr)
			std::cout << "Movie Terminator 2 not in collection.\n";
		aMovie = theCollection["Dark Phoenix"];
		if (aMovie != nullptr)
			std::cout << "In collection:\n" << *aMovie;
		std::cout << "-----------------------------------------\n\n";

	//	std::cout << "xu hao I de value shi"<<i << std::endl;
		return 0;
		
	//}

	

}


