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
	system("CLS");
	cout << endl << endl << " === Welcome to Admin Menu === " << endl;

}