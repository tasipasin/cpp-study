#include "Weapon.h"

// This is how to initialize static data
int Weapon::ammount_of_weapons{ 0 };

Weapon::Weapon()
    : Weapon{ 0 } {
    // Delegates the initialization to the other constructor
}

Weapon::Weapon(int ammo_amount, string type)
    : ammo_amount{ ammo_amount }, type{ type } {
    // Better initialization
    ++ammount_of_weapons;
}

Weapon::Weapon(const Weapon& original)
    : Weapon{ original.ammo_amount, original.type } {
}
Weapon::~Weapon() {
    --ammount_of_weapons;
}

void Weapon::set_ammo(int value) {
    this->ammo_amount = value;
}

int Weapon::get_ammo() {
    return this->ammo_amount;
}

bool Weapon::is_empty() {
    return get_ammo() == 0;
}

void Weapon::shoot() {
    this->ammo_amount--;
}

string Weapon::get_type() {
    return this->type;
}

int Weapon::get_ammount_of_weapons() {
    return ammount_of_weapons;
}