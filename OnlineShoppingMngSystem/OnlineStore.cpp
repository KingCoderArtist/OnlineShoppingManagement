#include "OnlineStore.h"
#include <iostream>
#include <fstream>
#include "Admin.h"

using namespace std;

// Blank the singleton store instance
OnlineStore* OnlineStore::instance = 0;

OnlineStore::OnlineStore() {
	curUser = 0;
}

void OnlineStore::initialize() {
	fstream fp;
	fp.open("db.txt", ios::in);
	if (!fp) {
		// File not exist
		// Add new Admin with email: admin@gmail.com password: 1234
		users.push_back(new Admin());
	}
	else {
		while (!fp.eof()) {
			string type_token;
			string user_type_token;
			string _email, _password, _name, _address, _number;
			fp >> type_token;
			cout << type_token << " ";
			if (type_token == "USER") {
				fp >> user_type_token;
				cout << user_type_token << " ";
				if (user_type_token == "0") { // Admin
					fp >> _email >> _password;
					cout << _email << " " << _password;
					users.push_back(new Admin(_email, _password));
				}
				else if (user_type_token == "1") { // Manager
					fp >> _email >> _password >> _name;
					cout << _email << " " << _password << " " << _name;
					users.push_back(new Manager(_email, _password, _name));
				}
				else if (user_type_token == "2") { // Customer
					fp >> _email >> _password >> _name >> _address >> _number;
					cout << _email << " " << _password << " " << _name << " " << _address << " " << _number;
					users.push_back(new Customer(_email, _password, _name, _address, _number));
				}
			}
			cout << endl;
		}
		fp.close();
	}
}


void OnlineStore::mainMenu() {
	string email, password, choice;
	while (true) {
		system("CLS");
		cout << "Welcome to Main Menu" << endl;
		cout << "Enter your choice (1-Login,2-Exit): ";
		cin >> choice;
		while (choice == "1") {
			cout << endl << " ========== LOGIN ========== " << endl << endl;
			cout << "Enter Email: ";
			cin >> email;
			cout << "Enter Password: ";
			cin >> password;

			curUser = authenticate(email, password);
			if (curUser) {
				curUser->userMenu();
				// when user exits userMenu. then redirects choice
				break;
			}
			else {
				cout << endl << "Login Failed: Wrong Email or Password" << endl;
			}
		}
		if (choice == "2") {
			// Exit app
			exit(1);
		}
	}
}

User* OnlineStore::authenticate(string _email, string _password) {
	for (User* user : users) {
		if (user->getEmail() == _email && user->getPassword() == _password) {
			return user;
		}
	}
	return NULL;
}

bool OnlineStore::addNewManager(string _email, string _password, string _name) {
	for (User* user : users) {
		if (*user == _email) {
			return false;
		}
	}
	users.push_back(new Manager(_email, _password, _name));
	saveToFile();
	return true;
}

bool OnlineStore::deleteManager(string _email) {
	for (User* user : users) {
		if (user->getType() == USER_TYPE_MANAGER && *user == _email) {
			users.remove(user);
			saveToFile();
			return true;
		}
	}
	return false;
}

bool OnlineStore::updateManager(string _email, string _password, string _name) {
	for (User* user : users) {
		if (user->getType() == USER_TYPE_MANAGER && *user == _email) {
			Manager* m_user = (Manager*)user;
			user->setPassword(_password);
			m_user->setName(_name);
			saveToFile();
			return true;
		}
	}
	return false;
}

void OnlineStore::showMangers() {
	int count = 0;
	printf(" === MANAGER LIST === \n");
	printf("%16s %16s %16s\n", "Email", "Name", "Password");
	for (User* user : users) {
		if (user->getType() == USER_TYPE_MANAGER) {
			Manager* m_user = (Manager *)user;
			printf("%16s %16s %16s\n", user->getEmail().c_str(), m_user->getName().c_str(), user->getPassword().c_str());
			count += 1;
		}
	}
	printf("Total: %d Managers Registered\n\n", count);
}

Manager* OnlineStore::searchManager(string _email) {
	for (User* user : users) {
		if (*user == _email) {
			return (Manager*)user;
		}
	}
	return NULL;
}


bool OnlineStore::addNewCustomer(string _email, string _password, string _name, string _address, string _number) {
	for (User* user : users) {
		if (*user == _email) {
			return false;
		}
	}
	users.push_back(new Customer(_email, _password, _name, _address, _number));
	saveToFile();
	return true;
}

bool OnlineStore::deleteCustomer(string _email) {
	for (User* user : users) {
		if (user->getType() == USER_TYPE_CUSTOMER && *user == _email) {
			users.remove(user);
			saveToFile();
			return true;
		}
	}
	return false;
}

bool OnlineStore::updateCustomer(string _email, string _password, string _name, string _address, string _number) {
	for (User* user : users) {
		if (user->getType() == USER_TYPE_CUSTOMER && *user == _email) {
			Customer* m_user = (Customer*)user;
			user->setPassword(_password);
			m_user->setName(_name);
			m_user->setAddress(_address);
			m_user->setNumber(_number);
			saveToFile();
			return true;
		}
	}
	return false;
}

void OnlineStore::showCustomers() {
	int count = 0;
	printf(" === CUSTOMER LIST === \n");
	printf("%16s %16s %16s %16s %16s\n", "Email", "Name", "Password", "Address", "Number");
	for (User* user : users) {
		if (user->getType() == USER_TYPE_CUSTOMER) {
			Customer* m_user = (Customer*)user;
			printf("%16s %16s %16s %16s %16s\n", user->getEmail().c_str(), m_user->getName().c_str(), user->getPassword().c_str(), m_user->getAddress().c_str(),
				m_user->getNumber().c_str());
			count += 1;
		}
	}
	printf("Total: %d Customers Registered\n\n", count);
}

Customer* OnlineStore::searchCustomer(string _email) {
	for (User* user : users) {
		if (*user == _email) {
			return (Customer*)user;
		}
	}
	return NULL;
}

void OnlineStore::saveToFile() {
	fstream fp;
	fp.open("db.txt", ios::out);
	for (User* user : users) {
		fp << *user;
		// cout << *user;
	}
	fp.close();
}

OnlineStore* OnlineStore::getInstance() {
	if (instance == 0) {
		instance = new OnlineStore();
		// Initialize the store.
		instance->initialize();
	}
	return instance;
}