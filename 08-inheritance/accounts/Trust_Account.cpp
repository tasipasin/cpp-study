#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance)
    : Savings_Account{ name, balance } {
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust_Account: " << account.name
        << ": " << account.balance
        << ", " << account.curr_withdrawal_count << " of " << Trust_Account::max_withdrawals_per_year << " withdrawals per year made"
        << ", " << Trust_Account::over_deposit_bonus << " overload deposit bonus"
        << ", " << Trust_Account::over_deposit_value << " over deposit value]";
    return os;
}

bool Trust_Account::deposit(double amount) {
    if (Savings_Account::deposit(amount)) {
        if (amount >= Trust_Account::over_deposit_value) {
            return Account::deposit(Trust_Account::over_deposit_bonus);
        }
        return true;
    }
    return false;
}

bool Trust_Account::withdraw(double amount) {
    this->curr_withdrawal_count++;
    return Savings_Account::withdraw(amount);
}