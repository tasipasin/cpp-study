#include<iostream>
#include<vector>
#include "Weapon.h"

using namespace std;

class Player {
    // Defines private attributes
    string name;
    int health;
    int xp;

    // Defines private methods
    // Since these methods have never been implemented
    // using them would cause an error.
    void talk(string message);
    bool is_dead();
};

class Account {
    // It determines that anyone, in any part of the code,
    // can access these members
public:
    // Defines attributes
    // The class attributes can be initialized as well
    string account_name{ "" };
    double balance{ 0 };


    // Defines methods
    bool deposit(double amount) {
        cout << "Depositing " << amount << " to " << this->account_name << endl;
        this->balance += amount;
        cout << "New Balance (" << this->account_name << "): " << this->balance << endl;
        return true;
    }
    bool withdraw(double amount);

    // These methods should be used to change and retrieve the 
    // attribute value
    void set_account_number(int value) {
        this->account_number = value;
    }
    int get_account_number() {
        return this->account_number;
    }
    // It determines that only the class should access these attributes
private:
    int account_number;
};

int main() {
    /** Declaring a new class and initializing it */
    {
        cout << "Declaring a new class and initializing it" << endl;
        Player tasi;
        Player steve;

        // Create object in the heap
        Player* zombie = new Player();
        // When creating objects in the heap (dynamically)
        // It's healthy to free the memory space after finished using it
        delete zombie;

        // We can use the objects like any variable else (arrays, vectors)
        Player players[]{ tasi,steve };

        Account tasi_account;
        vector<Account> accounts{ tasi_account };

    }

    cout << endl;

    /** Accessing Class Members (attributes and methods) */
    {
        cout << "Accessing Class Members (attributes and methods)" << endl;
        // When it's an object, we could access class members with the dot
        Account tasi_account;
        // Show default initilizer value (0)
        cout << "tasi_account.balance: " << tasi_account.balance << endl;
        // Determines new value
        tasi_account.balance = 100.0;
        // Show new value (100)
        cout << "tasi_account.balance: " << tasi_account.balance << endl;
        tasi_account.account_name = "tasi_account";

        Account* tasi_account_ptr = new Account();
        // We can do the same with object pointer using ->
        cout << "tasi_account_ptr.balance: " << tasi_account_ptr->balance << endl;
        // Determines new value
        tasi_account_ptr->balance = 120.0;
        // Show new value (100)
        cout << "tasi_account_ptr.balance: " << tasi_account_ptr->balance << endl;
        tasi_account_ptr->account_name = "tasi_account_ptr";

        // Same occurs with methods
        double balance_to_add{ 50.0 };
        tasi_account.deposit(balance_to_add);
        tasi_account_ptr->deposit(balance_to_add);
        delete tasi_account_ptr;

    }

    cout << endl;

    /** Class Member access modifiers */
    {
        cout << "Class Member access modifiers" << endl;
        // When it's an object, we could access class members with the dot
        Account tasi_account;
        cout << "Auto Initialized account number: " << tasi_account.get_account_number() << endl;
        // This will cause an error because the attribute is private
        // tasi_account.account_number = 123456;
        tasi_account.set_account_number(123456);
        cout << "Account number setted: " << tasi_account.get_account_number() << endl;
    }

    cout << endl;

    /** Declaring classes in files .h and implementing in .cpp */
    {
        cout << "Declaring classes in files .h and implementing in .cpp" << endl;
        Weapon ak;
        ak.set_ammo(30);
        cout << "Ammo on AK: " << ak.get_ammo() << endl;
        while (!ak.is_empty()) {
            ak.shoot();
            cout << "shoot";
        }
        cout << endl;
        cout << "Ammo on AK: " << ak.get_ammo() << endl;

        Weapon* m4 = new Weapon;
        m4->set_ammo(25);
        cout << "Ammo on M4: " << m4->get_ammo() << endl;
        while (!m4->is_empty()) {
            m4->shoot();
            cout << "shoot";
        }
        cout << endl;
        cout << "Ammo on M4: " << m4->get_ammo() << endl;

        // Never forget to delete a pointer created dynamically after using it
        delete m4;

        // Compiler automatically uses the correspondent constructor
        Weapon p2000{ 15 };
        cout << "Ammo on P2000: " << p2000.get_ammo() << endl;
        while (!p2000.is_empty()) {
            p2000.shoot();
            cout << "shoot";
        }
        cout << endl;
        cout << "Ammo on P2000: " << p2000.get_ammo() << endl;

        Weapon* awp = new Weapon(5);
        cout << "Ammo on AWP: " << awp->get_ammo() << endl;
        while (!awp->is_empty()) {
            awp->shoot();
            cout << "shoot";
        }
        cout << endl;
        cout << "Ammo on AWP: " << awp->get_ammo() << endl;

        // Never forget to delete a pointer created dynamically after using it
        delete awp;
    }

    cout << endl;

    /** Default Constructor Parameters */
    {
        cout << "Default Constructor Parameters" << endl;
        // Initializing with amount of ammo, but no type
        Weapon ak{ 30 };
        cout << "Ammo on AK: " << ak.get_ammo() << endl;
        cout << "Type of AK: " << ak.get_type() << endl;

        // Initializing with amount of ammo and a type
        Weapon p250{ 13, "pistol" };
        cout << "Ammo on P250: " << p250.get_ammo() << endl;
        cout << "Type of P250: " << p250.get_type() << endl;
    }

    cout << endl;

    /** Copy constructor */
    {
        // Are provided by default by the the compiler (shallow copy)
        cout << "Copy constructor" << endl;
        cout << "Default Constructor Parameters" << endl;
        // Initializing with amount of ammo, but no type
        Weapon ak1{ 30, "rifle" };
        cout << "Ammo on AK1: " << ak1.get_ammo() << endl;
        cout << "Type of AK1: " << ak1.get_type() << endl;
        Weapon ak2{ ak1 };
        cout << "Ammo on AK2: " << ak2.get_ammo() << endl;
        cout << "Type of AK2: " << ak2.get_type() << endl;
        while (!ak1.is_empty()) {
            ak1.shoot();
            cout << "shoot";
        }
        cout << endl;
        cout << "Ammo on AK1: " << ak1.get_ammo() << endl;
        cout << "Type of AK1: " << ak1.get_type() << endl;
        cout << "Ammo on AK2: " << ak2.get_ammo() << endl;
        cout << "Type of AK2: " << ak2.get_type() << endl;

    }

    cout << endl;

    /** Static Class Member. */
    {
        // Static member belongs to the class, not the object
        cout << "Amount of weapons: " << Weapon::get_ammount_of_weapons() << endl;
        Weapon ak1{ 30, "rifle" };
        Weapon* m4 = new Weapon();
        Weapon* p2000 = new Weapon(20);
        Weapon awp;
        cout << "Amount of weapons: " << Weapon::get_ammount_of_weapons() << endl;
        Weapon ak2{ ak1 };
        cout << "Amount of weapons: " << Weapon::get_ammount_of_weapons() << endl;
        delete m4;
        delete p2000;
        cout << "Amount of weapons: " << Weapon::get_ammount_of_weapons() << endl;
    }
    return 0;
}