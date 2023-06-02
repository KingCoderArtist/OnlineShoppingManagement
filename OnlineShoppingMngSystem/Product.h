#pragma once
#include <string>

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
};

