#ifndef _CONCRETE_CLASS_H
#define _CONCRETE_CLASS_H
#include<string>
#include"AbstractClass.h"
#include<iostream>
using namespace std;

class ConcreteClass : public AbstractClass {
public:
    // Overriding the PVF make this class a Concrete class
    virtual void abstract() override {
        cout << "I'm on a concrete class" << endl;
    };
    virtual ~ConcreteClass() {};
};

#endif