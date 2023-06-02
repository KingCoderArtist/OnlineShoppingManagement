#include "Manager.h"
#include "OnlineStore.h"

Manager::Manager(string _email, string _password, string _name) 
	: User(_email, _password, USER_TYPE_MANAGER) {
	name = _name;
}

void Manager::userMenu() {
	string choice;
	system("CLS");
	cout << " === Welcome to Manager Menu === " << endl;
	cout << "Current Manager Name: " << name << endl;
	while (true) {
		cout << "Enter your choice (1-Manage Product,2-Manage Order,3-Sign Out): ";
		cin >> choice;
		if (choice == "1") {
			productMenu();
		}
		if (choice == "2") {
			orderMenu();
		}
		if (choice == "3") {
			return;
		}
	}
}

void Manager::print(ostream& out) {
	out << name;
}

string Manager::getName() { return name; }

void Manager::setName(string _name) { name = _name; }

void Manager::productMenu() {

}

void Manager::orderMenu() {

}