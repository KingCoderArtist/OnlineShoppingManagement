#pragma once
#include <list>
#include "User.h"
using namespace std;
class OnlineStore
{
private:
	// User List
	list<User> users;
	// singleton store instance
	static OnlineStore* instance;
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

	static OnlineStore* getInstance();
protected:
};

