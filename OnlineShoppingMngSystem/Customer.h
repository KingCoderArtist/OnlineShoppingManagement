#pragma once
#include "User.h"
class Customer :
	public User
{
private:
	string name;
	string address;
	string number;
public:
	Customer(string _email, string _password, string _name, string _address, string _number);
	void userMenu();
	void showOrders();
	void placeOrderMenu();
	void print(ostream&);
	string getName();
	void setName(string _name);
	string getAddress() { return address; }
	void setAddress(string _address) { address = _address; }
	string getNumber() { return number; }
	void setNumber(string _number) { number = _number; }
};

