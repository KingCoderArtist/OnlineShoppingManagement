#include "Customer.h"
#include "OnlineStore.h"

Customer::Customer(string _email, string _password, string _name, string _address, string _number)
	: User(_email, _password, USER_TYPE_CUSTOMER) {
	name = _name;
	address = _address;
	number = _number;
}

void Customer::userMenu() {

}

void Customer::print(ostream& out) {
	out << name << " " << address << " " << number;
}

string Customer::getName() { return name; }

void Customer::setName(string _name) { name = _name; }