#ifndef _WARRIOR_H
#define _WARRIOR_H
#include "Character.h"
#include<iostream>

using namespace std;

class Warrior : public Character {

public:
    Warrior(string name, int strenght)
        :Character{ name, 100 }, strenght{ strenght } {
    };

    void attack(Character& enemy) {
        enemy.take_damage(this->strenght);
    }

    // Takes an amount of damage
    void take_damage(int damage_taken) {
        Character::take_damage(damage_taken);
        if (this->get_health() < 0) {
            on_dead();
        }
    }

private:
    void on_dead() {
        cout << "Warrior is dead" << endl;
    }
private:
    int strenght;
};

#endif