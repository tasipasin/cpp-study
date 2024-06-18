#ifndef _MONEY_MONEY_H
#define _MONEY_MONEY_H

#include <iostream>

using namespace std;

class Money {
    friend Money operator+(const Money& left, const Money& right);
    friend ostream& operator<<(ostream& os, const Money& rhs);
    int dollars;
    int cents;
public:
    Money(int dollars, int cents);
    Money(int total);
    int get_dollars() const { return dollars; }
    int get_cents() const { return cents; }

    bool operator==(const Money& money);
    bool operator!=(const Money& money);

};

#endif //_MONEY_MONEY_H
