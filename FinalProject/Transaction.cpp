#define _CRT_SECURE_NO_WARNINGS
#include "Transaction.h"
Transaction::Transaction(double amount, time_t date, const string& categories, const string& description, const PaymentMethod& paymentMethod)
    : amount(amount), date(date), categories(categories), description(description), paymentMethod(paymentMethod) {}

double Transaction::getAmount() const {
    return amount;
}

time_t Transaction::getDate() const {
    return date;
}

string Transaction::getCategories() const {
    return categories;
}

string Transaction::getDescription() const {
    return description;
}

PaymentMethod Transaction::getPaymentMethod() const {
    return paymentMethod;
}

void Transaction::setBalance(double amount) {
    this->amount = 0.0;
}