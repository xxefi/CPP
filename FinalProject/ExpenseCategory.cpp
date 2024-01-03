#define _CRT_SECURE_NO_WARNINGS
#include "ExpenseCategory.h"

ExpenseCategory::ExpenseCategory(const string& categoryy, double summ)
    : category(categoryy), sum(summ) {}

string ExpenseCategory::getCategory() const {
    return category;
}

double ExpenseCategory::getSum() const {
    return sum;
}