#include "Admin.h"
#include <iostream>

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

		}
		if (choice == "2") {

		}
		if (choice == "3") {
			return;
		}
	}

}