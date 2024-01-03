#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H
#include <vector>
#include <map>
#include "Transaction.h"
#include "Wallet.h"
#include "Card.h"
#include "ExpenseCategory.h"

class ExpenceManager {
public:
    ExpenceManager() = default;

    void addTransaction(const Transaction& transaction);
    void addCategory(const string& category);
    void addWallet(const Wallet& wallet);
    void addCard(const Card& card);

    static bool compareTransactionByAmount(const Transaction& otherOne, const Transaction& otherTwo);

    vector<Transaction> getTransactionsByDate(time_t beginDate, time_t endDate) const;
    vector<Transaction> getTransactionsByMonth(time_t beginDate) const;
    vector<Transaction> getTransactionsByWeek(time_t beginDate) const;
    vector<Transaction> getTopTransactionsByMonth(time_t beginDate) const;
    vector<Transaction> getTopTransactionsByWeek(time_t beginDate) const;
    vector<Transaction> getTopCategoriesByMonth(time_t beginDate) const;
    vector<Transaction> getTopCategoriesByWeek(time_t beginDate) const;

private:
    vector<Transaction> transactions;
    vector<string> categories;
    vector<Wallet> wallets;
    vector<Card> cards;
};

#endif