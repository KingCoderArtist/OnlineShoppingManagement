#include "Order.h"

Order::Order(string _oin, string _customer_email) {
	oin = _oin;
	customer_email = _customer_email;
	price = 0;
	count = 0;
}

Order::Order(string _oin, string _customer_email, double _price, int _count) {
	oin = _oin;
	customer_email = _customer_email;
	price = _price;
	count = _count;
}