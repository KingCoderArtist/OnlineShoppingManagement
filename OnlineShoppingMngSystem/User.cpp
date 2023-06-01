#include "User.h"

User::User(string _email, string _password, int _type) {
	email = _email;
	password = _password;
	type = _type;
}

string User::getEmail() { return email; }
string User::getPassword() { return password; }