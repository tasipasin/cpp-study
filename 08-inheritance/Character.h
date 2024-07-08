#ifndef _CHARACTER_H
#define _CHARACTER_H
#include<string>
using namespace std;

class Character {
public:

    Character(string name, int health)
        :name{ name }, health{ health } {};

    // Returns character name
    string get_name() const {
        return this->name;
    }

    // Returns character health
    int get_health() const {
        return this->health;
    }

    // Takes an amount of damage
    void take_damage(int damage_taken) {
        this->health -= damage_taken;
    }
protected:
    void on_dead() const {
        // Do nothing
    }

private:
    string name;
    int health;
};
#endif