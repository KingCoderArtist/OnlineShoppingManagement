#pragma once
#include <string>
#include <iostream>

using namespace std;
class Product
{
private:
	// Product Identification Number
	string pin;
	string name;
	double rate;
public:
	Product(string, string, double);
	bool operator==(string _pin);
	string getPin() { return pin; }
	string getName() { return name; }
	double getRate() { return rate; }
	void setName(string _name) { name = _name; }
	void setRate(double _rate) { rate = _rate; }
	friend ostream& operator<<(ostream& out, Product& product) {
		out << "PRODUCT " << product.pin << " " << product.name << " " << product.rate << endl;
		return out;
	}
};

