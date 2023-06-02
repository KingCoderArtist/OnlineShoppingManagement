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
	void print(ostream&);
	string getName();
	void setName(string _name);
	void productMenu();
	void orderMenu();
};

