#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
public:
    Card() = default;
    Card(const string& cardType, const double& balance);

    string getCardType() const;
    void setInitialBalance(double initialBalance);
    double getBalance() const;
    void updateBalance(double amount);

private:
    string cardType;
    double balance;
};

#endif // CARD_H
