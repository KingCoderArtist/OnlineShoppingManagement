// OnlineShoppingMngSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OnlineStore.h"

int main()
{
	OnlineStore *store = OnlineStore::getInstance();
	store->mainMenu();
}
