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
	string choice;
	string _pin, _name;
	double _rate = 0;
	int _amount = 0;
	system("CLS");
	cout << " === Welcome to Manage Product for Manager Menu === " << endl;
	while (true) {
		cout << "1 - Add Product" << endl;
		cout << "2 - Delete Product" << endl;
		cout << "3 - Edit Product" << endl;
		cout << "4 - View Product" << endl;
		cout << "5 - Search Product" << endl;
		cout << "6 - Return to Manager Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == "1") {
			// Add Product
			system("CLS");
			cout << " === ADD PRODUCT === " << endl;
			cout << "Enter Product Identification Number: ";
			cin >> _pin;
			cout << "Enter Product Name: ";
			cin >> _name;
			cout << "Enter Rate: ";
			cin >> _rate;
			cout << "Enter Amount: ";
			cin >> _amount;
			if (_pin != "" && _name != "" && _rate != 0) {
				bool flag = parent->addNewProduct(_pin, _name, _rate, _amount);
				if (flag) {
					cout << "Added Successfully!" << endl;
				}
				else {
					cout << "Identification Number Already Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "2") {
			// Delete Product
			system("CLS");
			cout << " === DELETE PRODUCT === " << endl;
			cout << "Enter Product Identification Number: ";
			cin >> _pin;
			if (_pin != "") {
				bool flag = parent->deleteProduct(_pin);
				if (flag) {
					cout << "Deleted Successfully!" << endl;
				}
				else {
					cout << "Identification Number Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "3") {
			// Edit Product
			system("CLS");
			cout << " === Edit PRODUCT === " << endl;
			cout << "Enter Identification Number to edit: ";
			cin >> _pin;

			cout << "Enter Name: ";
			cin >> _name;
			cout << "Enter Rate: ";
			cin >> _rate;
			cout << "Enter Amount: ";
			cin >> _amount;

			if (_pin != "" && _name != "" && _rate != 0) {
				bool flag = parent->updateProduct(_pin, _name, _rate, _amount);
				if (flag) {
					cout << "Updated Successfully!" << endl;
				}
				else {
					cout << "Identification Number Not Exist!" << endl;
				}
			}
			else {
				cout << "Missing information! Please Try Again!" << endl;
			}
		}
		if (choice == "4") {
			// View Products
			parent->showProducts();
		}
		if (choice == "5") {
			// Search Product
			system("CLS");
			cout << " === Search PRODUCT === " << endl;
			cout << "Enter Identification Number to search: ";
			cin >> _pin;

			Product* product = parent->searchProduct(_pin);
			if (product) {
				cout << "Name: " << product->getName() << endl;
				cout << "Rate: " << product->getRate() << endl;
				cout << "Amount: " << product->getAmount() << endl;
			}
			else {
				cout << "Identification Number Not Exist!" << endl;
			}
		}
		if (choice == "6") {
			// Return to Manager Menu
			return;
		}
	}
}

void Manager::orderMenu() {

}