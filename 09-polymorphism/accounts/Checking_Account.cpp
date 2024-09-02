#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{ name, balance } {
}

void Checking_Account::print(std::ostream& os) const {
    // Defines the precision for float variables
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance << ", " << Checking_Account::withdrawal_fee << " withdrawal fee]";
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + Checking_Account::withdrawal_fee);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

double Checking_Account::get_balance() const {
    return Account::get_balance();
}