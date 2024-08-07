#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    // Defines the precision for float variables
    cout.precision(2);
    cout << fixed;

    // Defines a set of accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{ "Larry" });
    accounts.push_back(Account{ "Moe", 2000 });
    accounts.push_back(Account{ "Curly", 5000 });

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings 
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{ "Superman" });
    sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
    sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking
    vector<Checking_Account> ck_accounts;
    ck_accounts.push_back(Checking_Account{});
    ck_accounts.push_back(Checking_Account{ "Tasi" });
    ck_accounts.push_back(Checking_Account{ "Messi", 2000 });

    display(ck_accounts);
    deposit(ck_accounts, 1000);
    withdraw(ck_accounts, 50);
    withdraw(ck_accounts, 50);

    // Trust
    vector<Trust_Account> tst_accounts;
    tst_accounts.push_back(Trust_Account{});
    tst_accounts.push_back(Trust_Account{ "Tasi" });
    tst_accounts.push_back(Trust_Account{ "Messi", 2000 });

    display(tst_accounts);
    deposit(tst_accounts, 5000);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);

    return 0;
}

