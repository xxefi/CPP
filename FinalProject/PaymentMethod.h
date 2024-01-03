#pragma once
#include <iostream>
using namespace std;
enum PaymentMethod {
	CASH,
	CARD
};

ostream& operator << (ostream& os, const PaymentMethod& paymentMethod);