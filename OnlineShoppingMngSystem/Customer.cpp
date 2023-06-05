#include "Customer.h"
#include "OnlineStore.h"

Customer::Customer(string _email, string _password, string _name, string _address, string _number)
	: User(_email, _password, USER_TYPE_CUSTOMER) {
	name = _name;
	address = _address;
	number = _number;
}

void Customer::userMenu() {
	string choice;
	system("CLS");
	cout << " === Welcome to Customer Menu === " << endl;
	cout << "Current Customer Name: " << name << endl;
	while (true) {
		cout << "Enter your choice (1-Show Orders,2-Place a Order,3-Sign Out): ";
		cin >> choice;
		if (choice == "1") {
			showOrders();
		}
		if (choice == "2") {
			placeOrderMenu();
		}
		if (choice == "3") {
			return;
		}
	}
}

void Customer::showOrders() {

}

void Customer::placeOrderMenu() {
	string choice;
	string _pin;
	int _count;
	Order* order;
	OrderItem* orderItems[64];
	int itemCnt = 0;
	system("CLS");
	cout << " === Welcome to Place a Order Menu for Customer === " << endl;
	while (true) {
		cout << "Enter your choice (1-Show Cart,2-Add Product into the Cart,3-Place Order,4-Return to Customer Menu): ";
		cin >> choice;
		if (choice == "1") {
			// show cart
		}
		if (choice == "2") {
			// add product into the cart
			parent->showProducts();
			cout << "Enter Product Identification Number";
			cin >> _pin;
			cout << "Enter Amount you are going to buy";
			cin >> _count;

			Product* product = parent->searchProduct(_pin);
			if (product) {

			}
		}
		if (choice == "3") {
			// place order
		}
		if (choice == "4") {
			return;
		}
	}
}

void Customer::print(ostream& out) {
	out << name << " " << address << " " << number;
}

string Customer::getName() { return name; }

void Customer::setName(string _name) { name = _name; }