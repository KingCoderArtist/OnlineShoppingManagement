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
void User::setPassword(string _password) { password = _password; }
int User::getType() { return type; }
bool User::operator==(string _email) {
	return email == _email;
}