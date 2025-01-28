#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main() {
    // test your code here
    Checking_Account ca{ "Tasi", 0.0 };
    try {
        Checking_Account ca2{ "Tasi Neg", -3.0 };
    }
    catch (const IllegalBalanceException& ex) {
        cerr << ex.what() << endl;
    }

    try {
        ca.withdraw(20);
    }
    catch (const InsufficentFundsException& ex) {
        cerr << ex.what() << endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

