#include "PaymentMethod.h"


ostream& operator << (ostream& os, const PaymentMethod& paymentMethod) {
	switch (paymentMethod) {
	case PaymentMethod::CASH:
		os << "��������\n";
		break;
	case PaymentMethod::CARD:
		os << "������\n";
		break;
	default:
		os << "���������� ����� ������.\n";
		break;
	}
	return os;
}