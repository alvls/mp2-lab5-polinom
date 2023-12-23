#pragma once
#include <string>
#include <unordered_map>
#include "TSinglyList.h"


class monom {

public:
    int coef;
    unordered_map<char, int> vars;

    monom() = default;

    monom(string mon);

    string getVars();

    bool operator==(const monom& other) const;

    monom operator*(const monom& other) const;

    friend ostream& operator<<(ostream& stream, const monom& source) {

        if (source.coef > 0) { stream << '+' << source.coef; }

        else { stream << source.coef; }
        
        for (const auto& pair : source.vars) { stream << pair.first << '^' << pair.second; }
        return stream;
    }
};