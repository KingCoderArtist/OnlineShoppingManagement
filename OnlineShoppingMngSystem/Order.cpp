#include "Order.h"

Order::Order(string _oin, string _customer_email) {
	oin = _oin;
	customer_email = _customer_email;
	count = 0;
	price = 0;
}