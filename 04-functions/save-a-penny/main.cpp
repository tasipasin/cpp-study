/**
 * Recursion study.
 * Calculate how much money you would have if you double a penny every day.
*/
#include <iomanip>
#include <iostream>

using namespace std;

/**
 * Recursive function to calculate how much money you would have doubling it every day.
 * @param days Amount of days doubling money.
 * @param start Amount of money you start with.
 * @return Amount of money you would have after these days.
*/
double a_penny_doubled_everyday(int days, double start = 0.01);

int main()
{
    double total_amount{ a_penny_doubled_everyday(18) };
    cout << "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10)
        << total_amount;
    return 0;
}

double a_penny_doubled_everyday(int days, double start)
{
    if (days <= 1) {
        return start;
    }
    return a_penny_doubled_everyday(--days, start * 2);
}