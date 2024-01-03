#include "PaymentMethod.h"


ostream& operator << (ostream& os, const PaymentMethod& paymentMethod) {
	switch (paymentMethod) {
	case PaymentMethod::CASH:
		os << "Наличные\n";
		break;
	case PaymentMethod::CARD:
		os << "Картой\n";
		break;
	default:
		os << "Непонятный метод оплаты.\n";
		break;
	}
	return os;
}