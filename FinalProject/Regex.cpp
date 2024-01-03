#include "Regex.h"
#define _CRT_SECURE_NO_WARNINGS
Regex::Regex(const string& txt) {
    this->txt = txt;
    regex txtRegex("\\.txt$");
}

string Regex::getTxt() const {
    return txt;
}