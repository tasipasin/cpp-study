// Trust Account 
#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
private:
    // Default initializations for the class attributes
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr int max_withdrawals_per_year = 3;
    static constexpr double over_deposit_bonus = 50.00;
    static constexpr double over_deposit_value = 5000.00;
    int curr_withdrawal_count = 0;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance);
    // Overrides the Savings_Account::deposit method
    virtual bool deposit(double amount) override;
    // Overrides the Savings_Account::withdraw method
    virtual bool withdraw(double amount) override;
    virtual double get_balance() const override;
    virtual void print(std::ostream& os) const override;
    virtual ~Trust_Account() = default;
};

#endif