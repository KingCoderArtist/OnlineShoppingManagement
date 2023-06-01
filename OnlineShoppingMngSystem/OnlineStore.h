#pragma once
#include <list>
#include "User.h"
using namespace std;
class OnlineStore
{
private:
	// User List
	list<User *> users;
	// singleton store instance
	static OnlineStore* instance;

	// Current Authenticated User
	User* curUser;
	OnlineStore();
public:
	/* 
	initialize function is called first time once when program starts.
	it loads datas (users, orders, etc) from file.
	*/
	void initialize();
	/*
	After initialize main menu is called to loop
	*/
	void mainMenu();

	/*
	Authenticate User with Email and Password
	Return the pointer of User in the users list if exist
	Else Return Null
	*/
	User* authenticate(string _email, string _password);

	static OnlineStore* getInstance();
protected:
};

