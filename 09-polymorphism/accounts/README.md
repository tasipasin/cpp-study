## Inheritance Challenge ##

#### Description ####
You are provided, from the previous section, with a simple Account class hierarchy, and helper, that contains.
Account - Base class
Savings Account - Derived Account class
Checking Account - Derived Account class
Trust Account - Derived Savings Account class

#### The challenge is the following: ####

1. Make Account an Abstract Class.

2. Create an Interface called I_Printable, so all Account Types can be printable to an ostream using the overloaded insertion operator:
```cpp
std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
```

3. Modify the Account_Util files to have only one version of each function:
```cpp
void display(const std::vector<Account*> &accounts);
void deposit(const std::vector<Account*> &accounts, double amount);
void withdraw(const std::vector<Account*> &accounts, double amount);
```
    
Hints: 
* If the class has a virtual function, be sure to implement a virtual destructor. (destructor() = default).
