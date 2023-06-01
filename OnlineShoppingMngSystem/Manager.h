#pragma once
#include "User.h"
class Manager :
	public User
{
private:
	string name;
public:
	Manager(string _email, string _password, string _name);
	void userMenu();
};

