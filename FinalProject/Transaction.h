#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>
#include "PaymentMethod.h"

using namespace std;


class Transaction {
public:
    Transaction() = default;
    Transaction(double amount, time_t date, const string& categories, const string& description, const PaymentMethod& paymentMethod);

    double getAmount() const;
    time_t getDate() const;
    string getCategories() const;
    string getDescription() const;
    PaymentMethod getPaymentMethod() const;

    void setBalance(double amount);

private:
    double amount;
    PaymentMethod paymentMethod;
    time_t date;
    string categories;
    string description;
};

#endif
