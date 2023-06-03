#include "Product.h"

Product::Product(string _pin, string _name, double _rate, int _amount) {
	pin = _pin;
	name = _name;
	rate = _rate;
	amount = _amount;
}
bool Product::operator==(string _pin) {
	return pin == _pin;
}