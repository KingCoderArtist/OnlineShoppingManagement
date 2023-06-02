#pragma once
#include <list>
#include "User.h"
#include "Manager.h"
#include "Customer.h"
using namespace std;

#define USER_TYPE_ADMIN 0
#define USER_TYPE_MANAGER 1
#define USER_TYPE_CUSTOMER 2

class OnlineStore
{
private:
	// User List
	list<User *> users;
	// singleton store instance
	static OnlineStore* instance;

	// Current Authenticated User
	User* curUser;
public:
	OnlineStore();
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

	/*
	Add new Manager
	If _email exists return false
	If success return true
	*/
	bool addNewManager(string _email, string _password, string _name);
	/*
	Delete Manager
	If _email exists delete and return true
	else false
	*/
	bool deleteManager(string _email);
	/*
	Update Manager
	If _email exists update and return true
	else false
	*/
	bool updateManager(string _email, string _password, string _name);
	/*
	Search Manager
	If _email exist return Manager pointer
	else return NULL
	*/
	Manager* searchManager(string _email);
	void showMangers();

	/*
	Customer Functions the same as Manager function
	*/
	bool addNewCustomer(string _email, string _password, string _name, string _address, string _number);
	bool deleteCustomer(string _email);
	bool updateCustomer(string _email, string _password, string _name, string _address, string _number);
	Customer* searchCustomer(string _email);
	void showCustomers();


	/*
	Save to DB
	*/
	void saveToFile();
	static OnlineStore* getInstance();
protected:
};

