#include "Money.h"

Money::Money(int dollars, int cents)
    : dollars{ dollars }, cents{ cents } {

}

Money::Money(int total)
    : dollars{ total / 100 }, cents{ total % 100 } {

}

bool Money::operator==(const Money& money) {
    return this->cents == money.cents && this->dollars == money.dollars;

}
bool Money::operator!=(const Money& money) {
    return this->cents != money.cents || this->dollars != money.dollars;
}

Money operator+(const Money& left, const Money& right) {
    int leftTotal = left.cents + (left.dollars * 100);
    int rightTotal = right.cents + (right.dollars * 100);
    return Money{ leftTotal + rightTotal };
}

ostream& operator<<(ostream& os, const Money& rhs) {
    os << "dollars: " << rhs.dollars << " cents: " << rhs.cents;
    return os;
}