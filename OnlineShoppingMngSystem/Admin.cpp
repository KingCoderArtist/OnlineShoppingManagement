#include "Admin.h"
#include <iostream>
#include "OnlineStore.h"

using namespace std;
/*
	Add admin with email: admin@gmail.com
	password: 1234
	type: 0 (Admin)
*/
Admin::Admin() : User("admin@gmail.com", "1234", 0){
	
}

void Admin::userMenu() {
	string choice;
	system("CLS");
	cout << " === Welcome to Admin Menu === " << endl;
	while (true) {
		cout << "Enter your choice (1-Manage Manager,2-Manage Customer,3-Sign Out): ";
		cin >> choice;
		if (choice == "1") {
			managerMenu();
		}
		if (choice == "2") {

		}
		if (choice == "3") {
			return;
		}
	}

}

void Admin::managerMenu() {
	string choice;
	string _email, _password, _name;
	system("CLS");
	cout << " === Welcome to Admin Manage Account for Manager Menu === " << endl;
	while (true) {
		cout << "1 - Add Manager" << endl;
		cout << "2 - Delete Manager" << endl;
		cout << "3 - Edit Manager" << endl;
		cout << "4 - View Managers" << endl;
		cout << "5 - Search Manager" << endl;
		cout << "6 - Return to Admin Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			system("CLS");
			cout << " === ADD MANAGER === " << endl;
			cout << "Enter Email: ";
			cin >> _email;
			cout << "Enter Password: ";
			cin >> _password;
			cout << "Enter Username: ";
			cin >> _name;
			if (_email != "" && _password != "" && _name != "") {
				parent->addNewManager(_email, _password, _name);
			}
		}
		if (choice == "2") {

		}
		if (choice == "3") {

		}
		if (choice == "4") {

		}
		if (choice == "5") {

		}
		if (choice == "6") {
			return;
		}
	}
}

void Admin::customerMenu() {

}