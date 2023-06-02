#pragma once
#include <string>

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
};

