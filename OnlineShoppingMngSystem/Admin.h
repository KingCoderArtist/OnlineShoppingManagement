#pragma once
#include "User.h"
class Admin :
	public User
{
private:
public:
	Admin();
	Admin(string _email, string _password);
	void userMenu();
	void print(ostream&);
	void managerMenu();
	void customerMenu();
protected:
};

