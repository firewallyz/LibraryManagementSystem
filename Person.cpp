#include <string>
#pragma once
using namespace std;

class Person {
protected:
	string name;
	static unsigned long long personIdGenerator;
	unsigned long long id;
public:
	Person(string name) {
		this->name = name;
		this->id = ++personIdGenerator;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	unsigned long long getId() {
		return id;
	}
};

class Patron : public Person {
protected:
	string address;
	string phoneNumber;
	string email;
public:
	Patron(string name, string address, string phoneNumber, string email) : Person(name) {
		this->address = address;
		this->phoneNumber = phoneNumber;
		this->email = email;
	}

	string getAddress() {
		return address;
	}

	string getPhoneNumber() {
		return phoneNumber;
	}

	string getEmail() {
		return email;
	}

	void setAddress(string address) {
		this->address = address;
	}

	void setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	void setEmail(string email) {
		this->email = email;
	}
};

class Staff : public Person {
protected:
	string jobTitle;
	string employeeID;
public:
	Staff(string name, string jobTitle, string employeeID) : Person(name) {
		this->jobTitle = jobTitle;
		this->employeeID = employeeID;
	}

	string getJobTitle() {
		return jobTitle;
	}

	string getEmployeeID() {
		return employeeID;
	}

	void setJobTitle(string jobTitle) {
		this->jobTitle = jobTitle;
	}

	void setEmployeeID(string employeeID) {
		this->employeeID = employeeID;
	}
};
