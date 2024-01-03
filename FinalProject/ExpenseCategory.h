#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef EXPENSECATEGORY_H
#define EXPENSECATEGORY_H

#include <string>

using namespace std;

class ExpenseCategory {
public:
    ExpenseCategory() = default;
    ExpenseCategory(const string& categoryy, double summ);

    string getCategory() const;
    double getSum() const;

private:
    string category;
    double sum;
};

#endif
