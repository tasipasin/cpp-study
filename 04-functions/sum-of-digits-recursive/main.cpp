#include <iostream>

using namespace std;

int sum_of_digits(int n)
{
    int rest{n % 10};
    cout << "input: " << n << " rest: " << rest << endl;
    if (rest == n)
    {
        return n;
    }
    return rest + sum_of_digits(n / 10);
}

int main()
{
    int input{5678};
    int sum{sum_of_digits(input)};
    cout << "Sum of digits from " << input << " is: " << sum << endl;
    return 0;
}