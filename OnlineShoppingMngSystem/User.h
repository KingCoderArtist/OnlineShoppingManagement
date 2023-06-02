
#include <string>
#include <iostream>

using namespace std;

class OnlineStore;
#pragma once
class User
{
	/*
	Class Memebers are protected because
	it can be accessed by derivated classes
	*/
protected:
	string email;
	string password;
	/*
	0: Admin
	1: Manager
	2: Customer
	*/
	int type;
	// Parent Class Object
	OnlineStore* parent;
public:
	User(string, string, int);
	// Abstract Pattern
	virtual void userMenu() = 0;
	// For managers, customers
	virtual void print(ostream&) = 0;
	string getEmail();
	string getPassword();
	void setPassword(string _password);
	bool operator==(string _email);
	int getType();
	friend ostream& operator<<(ostream& out, User& user) {
		out << "USER " << user.type << " " << user.email << " " << user.password << " ";
		user.print(out);
		out << endl;
		return out;
	}
};

