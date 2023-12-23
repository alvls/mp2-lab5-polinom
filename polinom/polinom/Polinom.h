#pragma once
#include <string>
#include "Monom.h"


class polinom {

public:
    polinom() = default;

    polinom(string polinom);

    double inPoint(double x, double y, double z);

    void bringingSimilar();

    polinom sum(const polinom& pm);

    polinom mult(const polinom& pm);

    friend ostream& operator<<(ostream& stream, const polinom& source) {

        stream << source.tlist;
        return stream;
    }

private:
    TSinglyList<monom> tlist;
};