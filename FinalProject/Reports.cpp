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
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        out << "������� �����: " << endl;
        for (const auto& transaction : transactions) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "������� ����� ������� ������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""������� �����"" � ����!" << endl;
    }
    out.close();
}

void Reports::generateWeeksReport(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> weekTransactions = expenceManager.getTransactionsByWeek(time(nullptr));
        out << "��������� �����: " << endl;

        for (const auto& transaction : weekTransactions) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "��������� ����� ������� ������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""��������� ����� "" � ����!" << endl;
    }
    out.close();
}

void Reports::generateMonthsReport(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> monthsTransaction = expenceManager.getTransactionsByMonth(time(nullptr));
        out << "�������� �����: " << endl;

        for (const auto& transaction : monthsTransaction) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "�������� ����� ������� ������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""�������� ����� "" � ����!" << endl;
    }
    out.close();
}

void Reports::generateTopTransactionsByMonths(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topTransactionsByMonths = expenceManager.getTopTransactionsByMonth(time(nullptr));
        out << "��� 3 ���������� �� �����: " << endl;
        for (const auto& transaction : topTransactionsByMonths) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "��� 3 ���������� �� ����� ������� �������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""��� 3 ���������� �� ����� "" � ����!" << endl;
    }
    out.close();
}

void Reports::generateTopTransactionsByWeeks(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topTransactionsByWeeks = expenceManager.getTopTransactionsByWeek(time(nullptr));
        out << "��� 3 ���������� �� ������: " << endl;
        for (const auto& transaction : topTransactionsByWeeks) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "��� 3 ���������� �� ������ ������� �������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""��� 3 ���������� �� ������ "" � ����!" << endl;
    }
    out.close();
}

void Reports::generateTopCategoriesByMonths(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topCategoriesByMonths = expenceManager.getTopCategoriesByMonth(time(nullptr));
        out << "��� 3 ��������� �� �����: " << endl;
        for (const auto& transaction : topCategoriesByMonths) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "��� 3 ��������� �� ����� ������� �������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""��� 3 ��������� �� ����� "" � ����!" << endl;
    }
    out.close();
}

void Reports::generateTopCategoriesByWeeks(const vector<Transaction>& transactions, const string& file) {
    ofstream out(file);
    if (!out) {
        cout << "�� ������� ������� ����! " << endl;
        return;
    }
    else {
        ExpenceManager expenceManager;
        vector<Transaction> topCategoriesByWeeks = expenceManager.getTopCategoriesByWeek(time(nullptr));
        out << "��� 3 ��������� �� ������: " << endl;
        for (const auto& transaction : topCategoriesByWeeks) {
            out << "����: " << transaction.getDate() << endl;
            out << "���������: " << transaction.getCategories() << endl;
            out << "�����: " << transaction.getAmount() << endl;
            out << "��������: " << transaction.getDescription() << endl;
            out << "� ���� ���� ������� ������: " << transaction.getPaymentMethod() << endl;
        }
    }
    if (out.good()) {
        cout << "��� 3 ��������� �� ������ ������� �������� � ����." << endl;
    }
    else {
        cout << "�� ������� �������� ""��� 3 ��������� �� ������ "" � ����!" << endl;
    }
    out.close();
}