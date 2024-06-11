#include <iostream>
#include <vector>
#include "Book.cpp"
#include "Person.cpp"
#pragma once
using namespace std;

/*
* Class to present the library
* Fields and methods are static as this LMS manages only 1 library
*/

class Library { //Library has a name and contains a collection of different items
protected:
	static vector<Book*> books;
	static vector<Patron*> patrons;
	//static vector<Staff*> staffs;
	static string libraryName;

public:

	static string getLibName() {
		return libraryName;
	}

	static void setLibName(string libName) {
		libraryName = libName;
	}

	//The library is managed by the child classes of "Manage"
	friend class ManageBooks;
	friend class ManagePatrons;
};
