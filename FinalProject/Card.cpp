#define _CRT_SECURE_NO_WARNINGS
#include "Card.h"
Card::Card(const string& cardType, const double& balance) {
    this->cardType = cardType;
    this->balance = balance;
}

string Card::getCardType() const {
    return cardType;
}

void Card::setInitialBalance(double initialBalance) {
    this->balance = initialBalance;
}

double Card::getBalance() const {
    return balance;
}

void Card::updateBalance(double amount) {
    balance += amount;
}
