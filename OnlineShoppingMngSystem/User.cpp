#include "User.h"
#include "OnlineStore.h"

User::User(string _email, string _password, int _type) {
	email = _email;
	password = _password;
	type = _type;
	parent = OnlineStore::getInstance();
}

string User::getEmail() { return email; }
string User::getPassword() { return password; }