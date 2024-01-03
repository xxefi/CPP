#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef REPORTS_H
#define REPORTS_H

#include <vector>
#include <string>
#include <fstream>
#include "Transaction.h"

using namespace std;

class Reports {
public:
    static void generateDaysReport(const vector<Transaction>& transactions, const string& file);
    static void generateWeeksReport(const vector<Transaction>& transactions, const string& file);
    static void generateMonthsReport(const vector<Transaction>& transactions, const string& file);
    static void generateTopTransactionsByMonths(const vector<Transaction>& transactions, const string& file);
    static void generateTopTransactionsByWeeks(const vector<Transaction>& transactions, const string& file);
    static void generateTopCategoriesByMonths(const vector<Transaction>& transactions, const string& file);
    static void generateTopCategoriesByWeeks(const vector<Transaction>& transactions, const string& file);
};

#endif