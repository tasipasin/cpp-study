#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    try : Account {name, balance} {
        std::cout << "Creating Checking Account for " << name << std::endl;
    }
    catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }


bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance  << "]";
}

