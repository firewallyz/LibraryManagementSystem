#include <string>
#pragma once
using namespace std;

/*
* Class to represent individual book
*/


class Book {
protected:
	static unsigned long long bookIdGenerator; //generates a unique id for each look
	string title;
	string author;
	unsigned int publicationYear;
	string isbn;
	string genre;
	unsigned long long id;
public:
	Book(string title, string author, unsigned int publicationYear, string isbn, string genre) {//initializer sets all class field values 
		this->title = title;
		this->author = author;
		this->publicationYear = publicationYear;
		this->isbn = isbn;
		this->genre = genre;
		this->id = ++bookIdGenerator; //past numbers are tracked and a new value is generated by incrementing the last value
	}

	//standard set and get methods for all class fields
	string getTitle() {
		return title;
	}

	string getAuthor() {
		return author;
	}

	unsigned int getPublicationYear() {
		return publicationYear;
	}

	string getIsbn() {
		return isbn;
	}

	string getGenre() {
		return genre;
	}

	unsigned long long getId() {
		return id;
	}

	void setTitle(string title) {
		this->title = title;
	}

	void setAuthor(string author) {
		this->author = author;
	}

	void setPublicationYear(unsigned int publicationYear) {
		this->publicationYear = publicationYear;
	}

	void setIsbn(string isbn) {
		this->author = author;
	}

	void setGenre(string genre) {
		this->genre = genre;
	}
};


