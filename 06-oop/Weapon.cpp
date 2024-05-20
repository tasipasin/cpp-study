#include "Weapon.h"

Weapon::Weapon() {
    this->ammo_amount = 0;
}

Weapon::Weapon(int ammo_amount) {
    this->ammo_amount = ammo_amount;
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