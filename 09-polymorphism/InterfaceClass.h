#ifndef _INTERFACE_CLASS_H
#define _INTERFACE_CLASS_H
#include<string>
#include<iostream>
using namespace std;

// Interface classes only have PVF
class InterfaceClass {
    friend ostream& operator<<(ostream& os, const InterfaceClass& obj) {
        obj.print(os);
        return os;
    }
public:
    virtual void print(ostream& os) const = 0;
    virtual ~InterfaceClass() {};
};

#endif