// These are Include Guards to guarantee the file will only be included once
#ifndef _WEAPON_H_
#define _WEAPON_H_
// This are an alternative do Include Guard (check compiler)
// #pragma once
#include<string>
using namespace std;

class Weapon {
private:
    int ammo_amount;
    string type;
    static int ammount_of_weapons;
public:
    // Default Constructor
    Weapon();
    // Determine the default value for weapon type
    Weapon(int ammo_amount, string type = "");
    // Copy constructor
    Weapon(const Weapon& original);
    ~Weapon();
    void set_ammo(int value);
    int get_ammo();
    bool is_empty();
    void shoot();
    string get_type();
    static int get_ammount_of_weapons();
};

#endif