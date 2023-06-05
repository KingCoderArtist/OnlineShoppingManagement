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
	double price;
	int count;
public:
	OrderItem(string, string, double, int);
	friend ostream& operator<<(ostream& out, OrderItem& orderItem) {
		out << "ORDERITEM " << orderItem.oin << " " << orderItem.pin << " " << orderItem.price << " " << orderItem.count << endl;
		return out;
	}
};

