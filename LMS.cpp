// LMS.cpp : Defines the entry point for the application.
//

#include "LMS.h"

using namespace std;
/*
* The main LMS file, containing the class for the main menu of the menu based UI and the main() method
*/

class MainMenu {
private:
	vector<Manage*> manages;
public:
	MainMenu() { //Main menu has an instance of all the "Manage" classes
		manages.push_back(new ManageBooks);
		manages.push_back(new ManagePatrons);
	}
	
	void mainMenu() {
		
		while (true) {
			cout << "Welcome to " << Library::getLibName() << " Library!" << endl;
			cout << endl;
			for (int i = 0; i < manages.size(); i++) { //Generate message for every category manager
				cout << "Type " << (i + 1) << " " << manages[i]->mainMenuMessage() << endl;
			}
			cout << "Type 0 to exit" << endl;
			unsigned int inputVal;
			cin >> inputVal;
			if (inputVal == 0) { //0 is used to end program
				cout << "GoodBye!";
				break;
			}
			else if (inputVal > manages.size()) {
				cout << "invalid entry, please try again";
			}
			else {
				manages[inputVal - 1]->runMenu();
			}
		}
		

	}
};

unsigned long long Book::bookIdGenerator = 0;
unsigned long long Person::personIdGenerator = 0;
string Library::libraryName = "";
vector<Book*> Library::books;
vector<Patron*> Library::patrons;

int main()
{

	try {
		string libName;
		cout << "Please enter the name of the library: " << endl;
		cin >> libName;
		Library::setLibName(libName); //Sets library name

		MainMenu runMenu = MainMenu();
		runMenu.mainMenu(); //Starts main menu
	}
	catch (exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}
