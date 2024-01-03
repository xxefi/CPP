#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef REGEX_H
#define REGEX_H
#include <string>
#include <regex>

using namespace std;

class Regex {
public:
    Regex() = default;
    Regex(const string& txt);

    string getTxt() const;

private:
    string txt;
};
#endif