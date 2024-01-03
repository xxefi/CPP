#define _CRT_SECURE_NO_WARNINGS
#include "Wallet.h"
Wallet::Wallet(const string& name, double balance)
    : name(name), balance(balance) {}

string Wallet::getName() const {
    return name;
}

void Wallet::balancee(double amount) {
    balance += amount;
}

double Wallet::getBalance() const {
    return balance;
}

void Wallet::updateBalance(double amount) {
    balance += amount;
}