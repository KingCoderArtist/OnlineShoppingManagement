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
	cout << "Welcome to Online Management Shopping System" << endl;

}

OnlineStore* OnlineStore::getInstance() {
	if (instance == 0) {
		instance = new OnlineStore();
		// Initialize the store.
		instance->initialize();
	}
	return instance;
}