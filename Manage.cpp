#include "Library.cpp"
#pragma once

using namespace std;

class Manage { //Manage base class
public:
	virtual string mainMenuMessage() = 0;
	virtual void runMenu() = 0;
};

class ManageBooks : public Manage {
private:
	int findBookIndexById(unsigned long long& id) {//Using its ID, use the position of the book in the library vector
		for (int i = 0; i < Library::books.size(); i++) {
			if (Library::books[i]->getId() == id) {
				return i;
			}
		}
	}

	void printBook(Book* book) {//Prints full information for individual book
		cout << "Title: " << book->getTitle() << "  |  " << "Author: " << book->getAuthor() << "  |  " << "Publication year: " << book->getPublicationYear() << "  |  "
			<< "isbn: " << book->getIsbn() << "  |  " "Genre: " << book->getGenre() << endl;
	}

public:
	string mainMenuMessage() {
		string message = "to manage library books.";
		return message;
	}
	void addNewBook(string title, string author, int publicationYear, string isbn, string genre) {//Initialize a new book instance and add to library vector
		Book* newBook = new Book(title, author, publicationYear, isbn, genre);
		Library::books.push_back(newBook);
	}

	Book* findBookById(unsigned long long& id) {//Using its ID, return the book instance pointer
		for (auto book : Library::books) {
			if (book->getId() == id) {
				return book;
				break;
			}
		}
	}

	//Edit existing books
	void editBookTitle(Book* bookToEdit, string& newName) {
		bookToEdit->setTitle(newName);
	}

	void editBookAuthor(Book* bookToEdit, string& author) {
		bookToEdit->setAuthor(author);
	}

	void editBookYear(Book* bookToEdit, int& publicationYear) {
		bookToEdit->setPublicationYear(publicationYear);
	}

	void editBookIsbn(Book* bookToEdit, string& isbn) {
		bookToEdit->setIsbn(isbn);
	}

	void editBookGenre(Book* bookToEdit, string& genre) {
		bookToEdit->setGenre(genre);
	}

	bool deleteBookById(unsigned long long& id) {
		if (int index = findBookIndexById(id)) {
			delete Library::books[index]; //delete the book instance
			Library::books.erase(Library::books.begin() + index);//remove book pointer from library vector
			return true;
		}
		else {
			return false;
		}
	}

	//search for and print books for a given title, may print multiple
	bool searchByTitle(string title) {
		bool atLeastOne = false;
		for (auto book : Library::books) {
			if (book->getTitle() == title) {
				printBook(book);
				atLeastOne = true;
			}
		}
		return atLeastOne;
	}

	//print info for every book
	void displayAllBooks() {
		for (auto book : Library::books) {
			printBook(book);
		}
	}

	//command line UI for manage books in library
	void runMenu() {

		while (true) {
			cout << "Type 1 to add new book" << endl;
			cout << "Type 2 to display all book" << endl;
			cout << "Type 3 to edit book details" << endl;
			cout << "Type 4 to delete a book" << endl;
			cout << "Type 5 to search book record by title" << endl;
			cout << "Type 0 to go back" << endl;
			int inputVal;
			cin >> inputVal;
			switch (inputVal) {
			case 0: //exit back to main menu
				cout << endl;
				return;
			case 1: { //pass the parameter values for the new book one by one, uses the addNewBook() method
				cout << "Please enter the title of the new book:" << endl;
				string newT = "";
				cin >> newT;
				cout << "Please enter the author of the new book:" << endl;
				string newA = "";
				cin >> newA;
				cout << "Please enter the publication year of the new book:" << endl;
				int newPY = 0;
				cin >> newPY;
				cout << "Please enter the isbn of the new book:" << endl;
				string newI = "";
				cin >> newI;
				cout << "Please enter the genre of the new book:" << endl;
				string newG = "";
				cin >> newG;
				addNewBook(newT, newA, newPY, newI, newG);
				cout << "New book added!" << endl;
				cout << endl;
				break; }
			case 2:
				displayAllBooks();
				cout << endl;
				break;
			case 3: { //finds book and gives further options to edit each field
				cout << "Please enter the book ID:";
				unsigned long long id;
				cin >> id;
				if (Book* bookToEdit = findBookById(id)) {
					cout << "Book found" << endl;
					printBook(bookToEdit);
					cout << "Type 1 to edit title" << endl;
					cout << "Type 2 to edit author" << endl;
					cout << "Type 3 to edit publication year" << endl;
					cout << "Type 4 to edit isbn" << endl;
					cout << "Type 5 to edit genre" << endl;
					cout << "Type 0 to cancel" << endl;
					int editInput;
					cin >> editInput;
					switch (editInput) {
					case 0:
						break;
					case 1: {
						string newTitle;
						cin >> newTitle;
						editBookTitle(bookToEdit, newTitle);
						cout << "Title updated" << endl;
						cout << endl;
						break; }
					case 2: {
						string newAuthor;
						cin >> newAuthor;
						editBookAuthor(bookToEdit, newAuthor);
						cout << "Author updated" << endl;
						cout << endl;
						break; }
					case 3: {
						int newPY;
						cin >> newPY;
						editBookYear(bookToEdit, newPY);
						cout << "Publication year updated" << endl;
						cout << endl;
						break; }
					case 4: {
						string newisbn;
						cin >> newisbn;
						editBookIsbn(bookToEdit, newisbn);
						cout << "isbn updated" << endl;
						cout << endl;
						break; }
					case 5: {
						string newGenre;
						cin >> newGenre;
						editBookGenre(bookToEdit, newGenre);
						cout << "Genre updated" << endl;
						cout << endl;
						break; }
					default:
						cout << "invalid action, please try again" << endl;
						break;
					}
				}
				else {
					cout << "can not found book ID, please check and try again" << endl;
				}
				break; }
			case 4: {
				cout << "Please enter the ID of the book you would like to delete:" << endl;
				unsigned long long deleteId;
				cin >> deleteId;
				bool result = deleteBookById(deleteId);
				if (result) {
					cout << "Book deleted" << endl;
				}
				else {
					cout << "Unable to find book" << endl;
				}
				cout << endl;
				break; }
			case 5: {
				cout << "Please enter the book title:" << endl;
				string title;
				cin >> title;
				bool result = searchByTitle(title);
				if (!result) {
					cout << "no book found" << endl;
					cout << endl;
				}
				break; }
			default:
				cout << "invalid entry, please try again" << endl;
				cout << endl;
				break;
			}
		}
	}
};
class ManagePatrons : public Manage {
private:
	int findPatronIndexById(int& id) {
		for (int i = 0; i < Library::patrons.size(); i++) {
			if (Library::patrons[i]->getId() == id) {
				return i;
			}
		}
	}

	void printPatron(Patron* patron) {
		cout << "Name: " << patron->getName() << "  |  " << "Address: " << patron->getAddress() << "  |  "
			<< "Phone Number: " << patron->getPhoneNumber() << "  |  " "Email: " << patron->getEmail() << endl;
	}

public:
	string mainMenuMessage() {
		string message = "to manage patrons.";
		return message;
	}

	void addNewPatron(string name, string address, string phoneNumber, string email) {
		Patron* newPatron = new Patron(name, address, phoneNumber, email);
		Library::patrons.push_back(newPatron);
	}

	void displayAllPatrons() {
		for (auto patron : Library::patrons) {
			printPatron(patron);
		}
	}

	void runMenu() {

		while (true) {
			cout << "Type 1 to add new patron" << endl;
			cout << "Type 2 to display all patron" << endl;
			cout << "Type 0 to go back" << endl;
			int inputVal;
			cin >> inputVal;
			switch (inputVal) {
			case 0:
				cout << endl;
				return;
			case 1: {
				cout << "Please enter the name of the new patron:" << endl;
				string newName = "";
				cin >> newName;
				cout << "Please enter the address of the new patron:" << endl;
				string newAddress = "";
				cin >> newAddress;
				cout << "Please enter the phone number of the new patron:" << endl;
				string newPhoneNumber = "";
				cin >> newPhoneNumber;
				cout << "Please enter the email of the new patron:" << endl;
				string newEmail = "";
				cin >> newEmail;
				addNewPatron(newName, newAddress, newPhoneNumber, newEmail);
				cout << "New patron added!" << endl;
				cout << endl;
				break; }
			case 2:
				displayAllPatrons();
				cout << endl;
				break;
			default:
				cout << "invalid entry, please try again" << endl;
				cout << endl;
				break;
			}
		}

	}


};
