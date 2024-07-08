#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{ name, balance } {
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << Checking_Account::withdrawal_fee << " withdrawal fee]";
    return os;
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + Checking_Account::withdrawal_fee);
}