#define _CRT_SECURE_NO_WARNINGS
#include "ExpenseManager.h"
#include <algorithm>
void ExpenceManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void ExpenceManager::addCategory(const string& category) {
    categories.push_back(category);
}

void ExpenceManager::addWallet(const Wallet& wallet) {
    wallets.push_back(wallet);
}

void ExpenceManager::addCard(const Card& card) {
    cards.push_back(card);
}

bool ExpenceManager::compareTransactionByAmount(const Transaction& otherOne, const Transaction& otherTwo) {
    return otherOne.getAmount() > otherTwo.getAmount();
}

vector<Transaction> ExpenceManager::getTransactionsByDate(time_t beginDate, time_t endDate) const {
    vector<Transaction> result1;
    for (const auto& transaction : transactions) {
        if (transaction.getDate() >= beginDate && transaction.getDate() <= endDate) {
            result1.push_back(transaction);
        }
    }
    return result1;
}

vector<Transaction> ExpenceManager::getTransactionsByMonth(time_t beginDate) const {
    vector<Transaction> result2;
    struct tm* timeInfo;
    timeInfo = localtime(&beginDate);
    timeInfo->tm_mday = 1;
    time_t startOfMonth = mktime(timeInfo);
    if (timeInfo->tm_mon == 12) {
        timeInfo->tm_mon = 0;
        timeInfo->tm_year++;
    }
    else {
        timeInfo->tm_mon++;
    }
    time_t startOfNextMonth = mktime(timeInfo);
    for (const auto& transaction : transactions) {
        if (transaction.getDate() >= startOfMonth && transaction.getDate() < startOfNextMonth) {
            result2.push_back(transaction);
        }
    }
    return result2;
}

vector<Transaction> ExpenceManager::getTransactionsByWeek(time_t beginDate) const {
    vector<Transaction> result3;
    struct tm* timeInfo;
    timeInfo = localtime(&beginDate);
    timeInfo->tm_wday = 1;
    time_t startOfWeek = mktime(timeInfo);
    if (timeInfo->tm_wday == 7) {
        timeInfo->tm_wday = 0;
        timeInfo->tm_year++;
    }
    else {
        timeInfo->tm_wday++;
    }
    time_t startOfNextWeek = mktime(timeInfo);
    for (const auto& transaction : transactions) {
        if (transaction.getDate() >= startOfWeek && transaction.getDate() < startOfNextWeek) {
            result3.push_back(transaction);
        }
    }
    return result3;
}

vector<Transaction> ExpenceManager::getTopTransactionsByMonth(time_t beginDate) const {
    vector<Transaction> transactionsMonth = getTransactionsByMonth(beginDate);
    sort(transactionsMonth.begin(), transactionsMonth.end(), [&](const Transaction& otherOne, const Transaction& otherTwo) {
        return compareTransactionByAmount(otherOne, otherTwo);
        });
    size_t minCount = min(transactionsMonth.size(), static_cast<size_t>(3));
    vector<Transaction> topTransactionsByMonth(transactionsMonth.begin(), transactionsMonth.begin() + minCount);
    return topTransactionsByMonth;
}

vector<Transaction> ExpenceManager::getTopTransactionsByWeek(time_t beginDate) const {
    vector<Transaction> transactionsByWeek = getTransactionsByWeek(beginDate);
    sort(transactionsByWeek.begin(), transactionsByWeek.end(), [&](const Transaction& otherOne, const Transaction& otherTwo) {
        return compareTransactionByAmount(otherOne, otherTwo);
        });
    size_t minCount = min(transactionsByWeek.size(), static_cast<size_t>(3));
    vector<Transaction> topTransactionsByWeek(transactionsByWeek.begin(), transactionsByWeek.begin() + minCount);
    return topTransactionsByWeek;
}

vector<Transaction> ExpenceManager::getTopCategoriesByMonth(time_t beginDate) const {
    map<string, double> categorySums;
    vector<Transaction> transactionsMonth = getTransactionsByMonth(beginDate);

    for (const auto& transaction : transactionsMonth) {
        categorySums[transaction.getCategories()] += transaction.getAmount();
    }

    vector<ExpenseCategory> sortedCategories;
    for (const auto& entry : categorySums) {
        sortedCategories.emplace_back(entry.first, entry.second);
    }

    sort(sortedCategories.begin(), sortedCategories.end(), [](const ExpenseCategory& a, const ExpenseCategory& b) {
        return a.getSum() > b.getSum();
        });

    size_t minCount = min(sortedCategories.size(), static_cast<size_t>(3));
    vector<Transaction> topCategoriesByMonth;
    for (size_t i = 0; i < minCount; ++i) {
        time_t timestamp = 0;
        for (const auto& transaction : transactions) {
            if (transaction.getCategories() == sortedCategories[i].getCategory()) {
                timestamp = transaction.getDate();
                break;
            }
        }
        topCategoriesByMonth.emplace_back(0.0, timestamp, sortedCategories[i].getCategory(), "", PaymentMethod::CASH);
    }
    return topCategoriesByMonth;
}

vector<Transaction> ExpenceManager::getTopCategoriesByWeek(time_t beginDate) const {
    map<string, double> categorySums;
    vector<Transaction> TransactionsWeek = getTransactionsByWeek(beginDate);

    for (const auto& transaction : TransactionsWeek) {
        categorySums[transaction.getCategories()] += transaction.getAmount();
    }

    vector<ExpenseCategory> sortedCategories;
    for (const auto& entry : categorySums) {
        sortedCategories.emplace_back(entry.first, entry.second);
    }

    sort(sortedCategories.begin(), sortedCategories.end(), [](const ExpenseCategory& a, const ExpenseCategory& b) {
        return a.getSum() > b.getSum();
        });

    size_t minCount = min(sortedCategories.size(), static_cast<size_t>(3));
    vector<Transaction> topCategoriesWeek;
    for (size_t i = 0; i < minCount; ++i) {
        time_t timestamp = 0;
        for (const auto& transaction : transactions) {
            if (transaction.getCategories() == sortedCategories[i].getCategory()) {
                timestamp = transaction.getDate();
                break;
            }
        }
        topCategoriesWeek.emplace_back(0.0, timestamp, sortedCategories[i].getCategory(), "", PaymentMethod::CASH);
    }
    return topCategoriesWeek;
}