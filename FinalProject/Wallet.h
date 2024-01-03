#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef WALLET_H
#define WALLET_H

#include <string>

using namespace std;

class Wallet {
public:
    Wallet() = default;
    Wallet(const string& name, double balance);

    string getName() const;
    void balancee(double amount);
    double getBalance() const;
    void updateBalance(double amount);

private:
    string name;
    double balance;
};

#endif
