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
public:
    // Constructor
    Weapon();
    Weapon(int ammo_amount);
    void set_ammo(int value);
    int get_ammo();
    bool is_empty();
    void shoot();
};

#endif