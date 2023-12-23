#include <sstream>
#include "Monom.h"

monom::monom(string mon) {

    int splitNum;

    if (mon[0] == '-' && isalpha(mon[1])) { coef = -1; splitNum = 1; }

    else if (isalpha(mon[0])) { coef = 1; splitNum = 0; }

    else
    {
        istringstream stream(mon);
        stream >> this->coef;
        splitNum = stream.tellg();
    }
    mon = mon.substr(splitNum);

    for (int i = 0; i < mon.length(); i++)
    {
        
        if (mon[i + 1] == '^')
        {
            vars[mon[i]] = atoi(&mon[i + 2]);
            i += 2;
        }
        else { vars[mon[i]] = 1; }
    }
}

string monom::getVars() {

    string vr;
    for (const auto& pair : vars) { vr += pair.first + ('^' + to_string(pair.second)); }
    return vr;
}

bool monom::operator==(const monom& other) const { return vars == other.vars; }

monom monom::operator*(const monom& other) const {

    monom result(*this);
    result.coef *= other.coef;

    for (const auto& pair : other.vars)
    {
        result.vars[pair.first] += pair.second;
    }
    return result;
}
