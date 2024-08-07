// Checking Account 
#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account : public Account {
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);
private:
    // Default initializations for the class attributes
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdrawal_fee = 1.5;
protected:
    double int_rate;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    // Overrides the Account:: withdraw method
    bool withdraw(double amount);
    // Inherits the Account::deposit methods
};

#endif