#include <iostream>
#include "sorted_list.h"
#include "monom.h"
#include "polinom.h"

int main()
{
    Polinom p;
    p.add({ 2,3,4,2 });
    p.add({ -4,5,5,6 });
    p.add({ 23,5,5,6 });
    for (const auto& monom : p.get_monoms()) {
        std::cout << monom << " ";
    }
    cout << endl;
    SortedList<Monom> list;
    for (size_t i = 0; i < 10; i += 2)
        list.insert_in_order({1.0,i,i,i});
    list.insert_in_order({2,3,4,2});
    list.insert_in_order({-4,5,5,6});
    list.insert_in_order({23,1,0,3});
    list.insert_in_order({23,1,4,0 });
    for (size_t i = 0; i < list.get_size(); i++)
        std::cout << list[i] << " ";
    Monom a(5, 2, 3, 4), b(3, 2, 3, 4);
    cout << endl;
    cout << "a+b=" << a + b << endl;
    cout << "a-b=" << a - b << endl;
    cout << "a*b=" << a * b << endl;
    cout << "a/b=" << a / b << endl;
    cout << "a= " << a.calculate(3.8, 4.2, 3.2345);
}
