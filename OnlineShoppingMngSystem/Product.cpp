#include "Product.h"

Product::Product(string _pin, string _name, double _rate) {
	pin = _pin;
	name = _name;
	rate = _rate;
}
bool Product::operator==(string _pin) {
	return pin == _pin;
}