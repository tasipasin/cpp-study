#ifndef _PEOPLE_H
#define _PEOPLE_H
#include<string>
#include"InterfaceClass.h"
#include<iostream>
using namespace std;

class People : public InterfaceClass {
public:
    // Implements the PVF from Interface Class
    virtual void print(ostream& os) const override {
        os << "We're people";
    }
    virtual ~People() {};
};

#endif