#include "Admin.h"
#include <iostream>
#include "OnlineStore.h"

using namespace std;
/*
	Add admin with email: admin@gmail.com
	password: 1234
	type: 0 (Admin)
*/
Admin::Admin() : User("admin", "1234", USER_TYPE_ADMIN){
	
}

Admin::Admin(string _email, string _password) : User(_email, _password, USER_TYPE_ADMIN) {

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
			customerMenu();
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
			// Add Manager
			system("CLS");
			cout << " === ADD MANAGER === " << endl;
			cout << "Enter Email: ";
			cin >> _email;
			cout << "Enter Password: ";
			cin >> _password;
			cout << "Enter Username: ";
			cin >> _name;
			if (_email != "" && _password != "" && _name != "") {
				bool flag = parent->addNewManager(_email, _password, _name);
				if (flag) {
					cout << "Added Successfully!" << endl;
				}
				else {
					cout << "Email Already Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "2") {
			// Delete Manager
			system("CLS");
			cout << " === DELETE MANAGER === " << endl;
			cout << "Enter Email: ";
			cin >> _email;
			if (_email != "") {
				bool flag = parent->deleteManager(_email);
				if (flag) {
					cout << "Deleted Successfully!" << endl;
				}
				else {
					cout << "Email Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "3") {
			// Edit Manager
			system("CLS");
			cout << " === Edit MANAGER === " << endl;
			cout << "Enter Email to edit: ";
			cin >> _email;

			cout << "Enter Password: ";
			cin >> _password;
			cout << "Enter Username: ";
			cin >> _name;

			if (_email != "" && _password != "" && _name != "") {
				bool flag = parent->updateManager(_email, _password, _name);
				if (flag) {
					cout << "Updated Successfully!" << endl;
				}
				else {
					cout << "Email Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "4") {
			// View Managers
			parent->showManagers();
		}
		if (choice == "5") {
			// Search Manager
			system("CLS");
			cout << " === Search MANAGER === " << endl;
			cout << "Enter Email to search: ";
			cin >> _email;

			Manager* m_user = parent->searchManager(_email);
			if (m_user) {
				cout << "Name: " << m_user->getName() << endl;
				cout << "Password: " << m_user->getPassword() << endl;
			}
			else {
				cout << "Email Not Exist!" << endl;
			}
		}
		if (choice == "6") {
			// Return to Admin Menu
			return;
		}
	}
}

void Admin::print(ostream& out) {

}

void Admin::customerMenu() {
	string choice;
	string _email, _password, _name, _address, _number;
	system("CLS");
	cout << " === Welcome to Admin Manage Account for Customer Menu === " << endl;
	while (true) {
		cout << "1 - Add Customer" << endl;
		cout << "2 - Delete Customer" << endl;
		cout << "3 - Edit Customer" << endl;
		cout << "4 - View Customers" << endl;
		cout << "5 - Search Customer" << endl;
		cout << "6 - Return to Admin Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			// Add Customer
			system("CLS");
			cout << " === ADD CUSTOMER === " << endl;
			cout << "Enter Email: ";
			cin >> _email;
			cout << "Enter Password: ";
			cin >> _password;
			cout << "Enter Username: ";
			cin >> _name;
			cout << "Enter Address: ";
			cin >> _address;
			cout << "Enter Number: ";
			cin >> _number;
			if (_email != "" && _password != "" && _name != "" && _address != "" && _number != "") {
				bool flag = parent->addNewCustomer(_email, _password, _name, _address, _number);
				if (flag) {
					cout << "Added Successfully!" << endl;
				}
				else {
					cout << "Email Already Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "2") {
			// Delete Customer
			system("CLS");
			cout << " === DELETE CUSTOMER === " << endl;
			cout << "Enter Email: ";
			cin >> _email;
			if (_email != "") {
				bool flag = parent->deleteCustomer(_email);
				if (flag) {
					cout << "Deleted Successfully!" << endl;
				}
				else {
					cout << "Email Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "3") {
			// Edit Customer
			system("CLS");
			cout << " === Edit CUSTOMER === " << endl;
			cout << "Enter Email to edit: ";
			cin >> _email;

			cout << "Enter Password: ";
			cin >> _password;
			cout << "Enter Username: ";
			cin >> _name;
			cout << "Enter Address: ";
			cin >> _address;
			cout << "Enter Number: ";
			cin >> _number;

			if (_email != "" && _password != "" && _name != "" && _address != "" && _number != "") {
				bool flag = parent->updateCustomer(_email, _password, _name, _address, _number);
				if (flag) {
					cout << "Updated Successfully!" << endl;
				}
				else {
					cout << "Email Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "4") {
			// View Customers
			parent->showCustomers();
		}
		if (choice == "5") {
			// Search Customer
			system("CLS");
			cout << " === Search CUSTOMER === " << endl;
			cout << "Enter Email to search: ";
			cin >> _email;

			Customer* m_user = parent->searchCustomer(_email);
			if (m_user) {
				cout << "Name: " << m_user->getName() << endl;
				cout << "Password: " << m_user->getPassword() << endl;
				cout << "Address: " << m_user->getAddress() << endl;
				cout << "Number: " << m_user->getNumber() << endl;
			}
			else {
				cout << "Email Not Exist!" << endl;
			}
		}
		if (choice == "6") {
			// Return to Admin Menu
			return;
		}
	}
}