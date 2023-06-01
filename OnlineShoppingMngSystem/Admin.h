#pragma once
#include "User.h"
class Admin :
	public User
{
private:
public:
	Admin();
	void userMenu();
	void print(ostream&);
	void managerMenu();
	void customerMenu();
protected:
};

