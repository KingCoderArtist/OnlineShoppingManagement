#pragma once
#include <string>
#include <iostream>

using namespace std;
class Order
{
private:
	// Order Identification Number
	string oin;
	string customer_email;
	double price;
	int count;
public:
	Order(string, string);
	Order(string, string, double, int);
	bool operator==(string _oin);
	friend ostream& operator<<(ostream& out, Order& order) {
		out << "ORDER " << order.oin << " " << order.customer_email << " " << order.price << " " << order.count << endl;
		return out;
	}
	string getOin() { return oin; }
	string getCustomerEmail() { return customer_email; }
	double getPrice() { return price; }
	void setPrice(double _price) { price = _price; }
	int getCount() { return count; }
	void setCount(int _count) { count = _count; }
};

