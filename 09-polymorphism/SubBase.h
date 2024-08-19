#ifndef _SUBBASE_H
#define _SUBBASE_H
#include<string>
#include<iostream>
#include "Base.h"
using namespace std;

class SubBase : public Base {
public:

    string display_not_virtual() {
        return "SubBase display not virtual";
    }

    // To ensure the function defined in a inherited class
    // is not defining a new one and it is overriding
    // the keyword override is added to the method definition
    // The compiler will show an error if the function signature
    // doesn't match with one in the inherited class
    virtual string display_virtual() override {
        return "SubBase display virtual";
    }

    // If a class has a virtual function, it should have a virtual destructor
    virtual ~SubBase() {
        cout << "Destructing SubBase" << endl;
    }
};
#endif