#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include "Reports.h"
#include "ExpenseManager.h"
void Reports::generateDaysReport(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        out << "Дневной отчёт: " << endl;
        for (const auto& transaction : transactions) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделана оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Дневной отчёт успешно записан в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Дневной отчёт"" в файл!" << endl;
    }
    out.close();
}

void Reports::generateWeeksReport(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> weekTransactions = expenceManager.getTransactionsByWeek(time(nullptr));
        out << "Недельный отчёт: " << endl;

        for (const auto& transaction : weekTransactions) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Недельный отчёт успешно записан в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Недельный отчёт "" в файл!" << endl;
    }
    out.close();
}

void Reports::generateMonthsReport(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> monthsTransaction = expenceManager.getTransactionsByMonth(time(nullptr));
        out << "Месячный отчёт: " << endl;

        for (const auto& transaction : monthsTransaction) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Месячный отчёт успешно сохранён в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Месячной отчёт "" в файл!" << endl;
    }
    out.close();
}

void Reports::generateTopTransactionsByMonths(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topTransactionsByMonths = expenceManager.getTopTransactionsByMonth(time(nullptr));
        out << "Топ 3 Транзакций за месяц: " << endl;
        for (const auto& transaction : topTransactionsByMonths) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Топ 3 Транзакций за месяц успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Топ 3 Транзакций за месяц "" в файл!" << endl;
    }
    out.close();
}

void Reports::generateTopTransactionsByWeeks(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topTransactionsByWeeks = expenceManager.getTopTransactionsByWeek(time(nullptr));
        out << "Топ 3 Транзакций за неделю: " << endl;
        for (const auto& transaction : topTransactionsByWeeks) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Топ 3 Транзакций за неделю успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Топ 3 Транзакций за неделю "" в файл!" << endl;
    }
    out.close();
}

void Reports::generateTopCategoriesByMonths(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topCategoriesByMonths = expenceManager.getTopCategoriesByMonth(time(nullptr));
        out << "Топ 3 Категорий за месяц: " << endl;
        for (const auto& transaction : topCategoriesByMonths) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Топ 3 Категорий за месяц успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Топ 3 Категорий за месяц "" в файл!" << endl;
    }
    out.close();
}

void Reports::generateTopCategoriesByWeeks(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "Не удалось открыть файл! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topCategoriesByWeeks = expenceManager.getTopCategoriesByWeek(time(nullptr));
        out << "Топ 3 Категорий за неделю: " << endl;
        for (const auto& transaction : topCategoriesByWeeks) {
            out << "Дата: " << transaction.getDate() << endl;
            out << "Категория: " << transaction.getCategories() << endl;
            out << "Сумма: " << transaction.getAmount() << endl;
            out << "Описание: " << transaction.getDescription() << endl;
            out << "С чего было сделано оплата: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "Топ 3 Категорий за неделю успешно записаны в файл." << endl;
    }
    else {
        cout << "Не удалось записать ""Топ 3 Категорий за неделю "" в файл!" << endl;
    }
    out.close();
}