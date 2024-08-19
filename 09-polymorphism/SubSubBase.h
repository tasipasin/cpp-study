#ifndef _SUBSUBBASE_H
#define _SUBSUBBASE_H
#include<string>
#include<iostream>
#include "SubBase.h"
using namespace std;

class SubSubBase : public SubBase {
public:

    string display_not_virtual() {
        return "SubSubBase display not virtual";
    }

    virtual string display_virtual() override {
        return "SubSubBase display virtual";
    }

    // If a class has a virtual function, it should have a virtual destructor
    virtual ~SubSubBase() {
        cout << "Destructing SubSubBase" << endl;
    }
};
#endif