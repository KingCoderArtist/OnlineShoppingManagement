
#include <string>

using namespace std;

class OnlineStore;
#pragma once
class User
{
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
};

