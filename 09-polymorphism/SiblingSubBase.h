#ifndef _SIBLINGSUBBASE_H
#define _SIBLINGSUBBASE_H
#include<string>
#include<iostream>
#include "Base.h"
using namespace std;

// The final keyword prevents the class/method of being overrided
class SiblingSubBase final : public Base {
public:

    string display_not_virtual() {
        return "SiblingSubBase display not virtual";
    }

    virtual string display_virtual() override {
        return "SiblingSubBase display virtual";
    }

    // If a class has a virtual function, it should have a virtual destructor
    virtual ~SiblingSubBase() {
        cout << "Destructing SiblingSubBase" << endl;
    }
};
#endif