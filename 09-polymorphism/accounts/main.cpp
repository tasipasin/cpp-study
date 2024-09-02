#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account.h"

using namespace std;

int main() {
    // Savings 
    vector<Account*> sav_accounts;
    sav_accounts.push_back(new Savings_Account());
    sav_accounts.push_back(new Savings_Account("Superman"));
    sav_accounts.push_back(new Savings_Account("Batman", 2000));
    sav_accounts.push_back(new Savings_Account("Wonderwoman", 5000, 5.0));

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking
    vector<Account*> ck_accounts;
    ck_accounts.push_back(new Checking_Account());
    ck_accounts.push_back(new Checking_Account("Tasi"));
    ck_accounts.push_back(new Checking_Account("Messi", 2000));

    display(ck_accounts);
    deposit(ck_accounts, 1000);
    withdraw(ck_accounts, 50);
    withdraw(ck_accounts, 50);

    // Trust
    vector<Account*> tst_accounts;
    tst_accounts.push_back(new Trust_Account());
    tst_accounts.push_back(new Trust_Account("Tasi"));
    tst_accounts.push_back(new Trust_Account("Messi", 2000));

    display(tst_accounts);
    deposit(tst_accounts, 5000);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);
    withdraw(tst_accounts, 50);

    return 0;
}

