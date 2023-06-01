
#include <string>

using namespace std;

class OnlineStore;
#pragma once
class User
{
private:
	string email;
	string password;
	/*
	0: Admin
	1: Manager
	2: Customer
	*/
	int type;
	// Parent Class Object
	OnlineStore* parent;
public:
	User(string, string, int);
	// Abstract Pattern
	virtual void userMenu() = 0;
	string getEmail();
	string getPassword();
};

