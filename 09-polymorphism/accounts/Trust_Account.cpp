#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance)
    : Savings_Account{ name, balance } {
}

void Trust_Account::print(std::ostream& os) const {
    // Defines the precision for float variables
    os.precision(2);
    os << std::fixed;
    os << "[Trust_Account: " << name
        << ": " << balance
        << ", " << curr_withdrawal_count << " of " << Trust_Account::max_withdrawals_per_year << " withdrawals per year made"
        << ", " << Trust_Account::over_deposit_bonus << " overload deposit bonus"
        << ", " << Trust_Account::over_deposit_value << " over deposit value]";
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
    if (this->curr_withdrawal_count < Trust_Account::max_withdrawals_per_year) {
        this->curr_withdrawal_count++;
        return Savings_Account::withdraw(amount);
    }
    return false;
}

double Trust_Account::get_balance() const {
    return Savings_Account::get_balance();
}