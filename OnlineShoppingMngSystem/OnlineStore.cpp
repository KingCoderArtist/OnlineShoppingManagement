#include "OnlineStore.h"
#include <iostream>

using namespace std;

// Blank the singleton store instance
OnlineStore* OnlineStore::instance = 0;

OnlineStore::OnlineStore() {

}

void OnlineStore::initialize() {

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