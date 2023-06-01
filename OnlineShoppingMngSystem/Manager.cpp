#include "Manager.h"

Manager::Manager(string _email, string _password, string _name) 
	: User(_email, _password, 1) {
	name = _name;
}

void Manager::userMenu() {

}