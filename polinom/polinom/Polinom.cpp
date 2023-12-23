#include "Polinom.h"
#include <cmath>

polinom::polinom(string polinom) {

    string mon = "";
    bool stop = false;
	
    for (char c : polinom)
    {
        c = tolower(c);
        if (c == '0') { stop = true; mon = ""; }

        else if (c == '-' || c == '+')
        {
            stop = false;

            if (!mon.empty())
            {
                monom mn(mon);
                tlist.pushBack(mn);
            }
            mon = (c == '-') ? "-" : "";
        }

        else if (c == ' ' || c == '*') { continue; }

        else if (stop == false) { mon += c; }
    }

    if (!mon.empty())
    {
        monom mn(mon);
        tlist.pushBack(mn);
    }
}

double polinom::inPoint(double x, double y, double z) {

    double sum = 0;
    double mult;

    for (int i = 0; i < tlist.size(); i++)
    {
        mult = 1;

        for (const auto& entry : tlist[i].vars)
        {
            if (entry.first == 'x') { mult *= pow(x, entry.second); }

            else if (entry.first == 'y') { mult *= pow(y, entry.second); }

            else { mult *= pow(z, entry.second); }
        }

        sum += tlist[i].coef * mult;
    }
    return sum;
}

void polinom::bringingSimilar() {

    TSinglyList<monom> newTlist;

    bool isSame = false;
    int totalCoef = 1;
    string str;

    for (int i = 0; i < tlist.size(); i++)
    {
        totalCoef = tlist[i].coef;
        str = tlist[i].getVars();
        isSame = false;

        for (int j = i + 1; j < tlist.size(); j++)
        {
            if (tlist[i] == tlist[j])
            {
                isSame = true;

                str += tlist[j].getVars();
                totalCoef += tlist[j].coef;
                tlist.removeAt(j);
                j--;
            }
        }
        if (isSame)
        {
            if (totalCoef != 0)
            {
                newTlist.pushBack(monom{ to_string(totalCoef) + str });
                tlist.removeAt(i);
                i--;
            }
        }
        else { newTlist.pushBack(tlist[i]); }
    }
    tlist = newTlist;
}

polinom polinom::sum(const polinom& pm) {

    polinom result;

    result.tlist = this->tlist + pm.tlist;

    result.bringingSimilar();
    return result;
}

polinom polinom::mult(const polinom& pm) {

    polinom result;

    result.tlist = this->tlist * pm.tlist;

    result.bringingSimilar();
    return result;
}
