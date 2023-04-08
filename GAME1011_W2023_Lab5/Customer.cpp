#include "Customer.h"

#include <iostream>

Customer::Customer()
{
	std::cout << "A customer is entering the pancake shop!\n";
}

Customer::~Customer()
{
	std::cout << "A customer is leaving the pancake shop!\n";
}

