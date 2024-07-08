#include"Character.h"
#include"Warrior.h"
#include<iostream>
using namespace std;

int main() {
    Character* tasi = new Character("Tasi", 100);
    cout << tasi->get_health() << endl;
    tasi->take_damage(20);
    cout << tasi->get_health() << endl;

    Warrior warrior{ "Warr", 30 };
    cout << warrior.get_name() << endl;
    cout << warrior.get_health() << endl;
    warrior.take_damage(12);
    cout << warrior.get_health() << endl;

    warrior.attack(*tasi);
    cout << tasi->get_health() << endl;
    while (warrior.get_health() > 0) {
        cout << "Warrior took 10 damage" << endl;
        warrior.take_damage(10);
    }
    delete tasi;
    return 0;
}