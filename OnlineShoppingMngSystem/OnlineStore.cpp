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
	// Add new Admin with email: admin@gmail.com password: 1234
	users.push_back(new Admin());
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
		if (user->getEmail() == _email) {
			return false;
		}
	}
	users.push_back(new Manager(_email, _password, _name));
	saveToFile();
	return true;
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

void OnlineStore::saveToFile() {
	fstream fp;
	fp.open("db.txt", ios::app | ios::out);
	for (User* user : users) {
		fp << user << endl;
		cout << user << endl;
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