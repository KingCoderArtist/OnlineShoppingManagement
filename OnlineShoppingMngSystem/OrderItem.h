#pragma once
#include <string>
#include <iostream>

using namespace std;
class OrderItem
{
private:
	// Order Identification Number
	string oin;
	// Product Identification Number
	string pin;
	// Product Name
	string pname;
	double price;
	int count;
public:
	OrderItem(string, string, string, double, int);
	friend ostream& operator<<(ostream& out, OrderItem& orderItem) {
		out << "ORDERITEM " << orderItem.oin << " " << orderItem.pin << " " << orderItem.pname << " " << orderItem.price << " " << orderItem.count << endl;
		return out;
	}
	double getPrice() { return price; }
	void setPrice(double _price) { price = _price; }
	int getCount() { return count; }
	void setCount(int _count) { count = _count; }
	string getPin() { return pin; }
	string getPname() { return pname; }
	string getOin() { return oin; }
};

