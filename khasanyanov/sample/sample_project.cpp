#include <iostream>
#include "sorted_list.h"
#include "monom.h"
#include "polynom.h"


bool isStringMatchingPattern(const std::string& str) {
    std::regex pattern("(-?\\d*)(x\\d*?)?(y\\d*?)?(z\\d*?)?");
    return std::regex_match(str, pattern);
}

int main()
{
    cout << isStringMatchingPattern("-5x755y6") << endl;
    cout << isStringMatchingPattern("xyz") << endl;
    cout << isStringMatchingPattern("-5x7y6+21x3y4z3") << endl;
    cout << isStringMatchingPattern("-x") << endl;
    Polynom p, s, c;
    p.add({ 2,3,4,2 });
    p.add({ -4,5,5,6 });
    p.add({ -23,5,5,6 });
    p.add(Monom{ -3,3,4,2 } * Monom{2, 2, 2, 2});
    p.add({ 35,-4,0,9 });
    p.add({ -7,0,0,0 });
    s = p.differential('z');
    p *= Monom{ 2,2,2,2 };
    cout << p << endl;
    cout << s << endl;
    s = p / p;
    cout << s << endl;
    cout  << "p= " << p.calculate(1, 2.4, 1) << endl;
    SortedList<Monom> list;
    for (int i = 0; i < 10; i += 2)
        list.insert_in_order({1.0,i,i,i}, [](Monom x, Monom y) {return x > y; });
    list.insert_in_order({2,3,4,2}, [](Monom x, Monom y) {return x > y; });
    list.insert_in_order({-4,5,5,6}, [](Monom x, Monom y) {return x > y; });
    list.insert_in_order({23,1,0,3}, [](Monom x, Monom y) {return x > y; });
    list.insert_in_order({23,1,4,0 }, [](Monom x, Monom y) {return x > y; });
    for (size_t i = 0; i < list.get_size(); i++)
        std::cout << list[i] << " ";
    Monom a(5, 2, 3, 4), b(3, 2, 3, 4);
    cout << endl;
    cout << "a+b=" << a + b << endl;
    cout << "a-b=" << a - b << endl;
    cout << "a*b=" << a * b << endl;
    cout << "a/b=" << a / b << endl;
}
