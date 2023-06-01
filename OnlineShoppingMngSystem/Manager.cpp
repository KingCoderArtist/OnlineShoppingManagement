#include "Manager.h"
#include "OnlineStore.h"

Manager::Manager(string _email, string _password, string _name) 
	: User(_email, _password, USER_TYPE_MANAGER) {
	name = _name;
}

void Manager::userMenu() {

}