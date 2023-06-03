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
	int amount;
public:
	Product(string, string, double, int);
	bool operator==(string _pin);
	string getPin() { return pin; }
	string getName() { return name; }
	double getRate() { return rate; }
	int getAmount() { return amount; }
	void setName(string _name) { name = _name; }
	void setRate(double _rate) { rate = _rate; }
	void setAmount(int _amount) { amount = _amount; }
	friend ostream& operator<<(ostream& out, Product& product) {
		out << "PRODUCT " << product.pin << " " << product.name << " " << product.rate << " " << product.amount << endl;
		return out;
	}
};

