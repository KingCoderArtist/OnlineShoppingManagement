#include "OnlineStore.h"
#include <iostream>
#include "Admin.h"

using namespace std;

// Blank the singleton store instance
OnlineStore* OnlineStore::instance = 0;

OnlineStore::OnlineStore() {

}

void OnlineStore::initialize() {
	// Add new Admin with email: admin@gmail.com password: 1234
	users.push_back(new Admin());
}


void OnlineStore::mainMenu() {
	string email, password;
	cout << "Welcome to Online Management Shopping System" << endl;
	while (true) {
		cout << endl << "First of all, you must login to use this system" << endl;

		cout << endl << " ========== LOGIN ========== " << endl << endl;
		cout << "Enter Email: ";
		cin >> email;
		cout << "Enter Password: ";
		cin >> password;

		curUser = authenticate(email, password);
		if (curUser) {
			curUser->userMenu();
		}
		else {
			cout << endl << "Login Failed: Wrong Email or Password" << endl;
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

OnlineStore* OnlineStore::getInstance() {
	if (instance == 0) {
		instance = new OnlineStore();
		// Initialize the store.
		instance->initialize();
	}
	return instance;
}