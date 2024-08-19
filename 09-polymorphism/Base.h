#ifndef _BASE_H
#define _BASE_H
#include<string>
#include<iostream>
using namespace std;

class Base {
public:

    string display_not_virtual() {
        return "Base display not virtual";
    }

    // Defining a function with the keyword virtual will allow
    // to override it in other inherited classes
    virtual string display_virtual() {
        return "Base display virtual";
    }

    // If a class has a virtual function, it should have a virtual destructor
    virtual ~Base() {
        cout << "Destructing Base" << endl;
    }
};
#endif