#ifndef _ABSTRACT_CLASS_H
#define _ABSTRACT_CLASS_H
#include<string>
#include<iostream>
using namespace std;


// An abstract class cannot be instantiated
class AbstractClass {
public:
    // In order to a class be a base abstract class
    // it must contain at least one pure virtual function
    // A Pure virtual function is used to make a class abstract
    // PVF do not provide implementations
    virtual void abstract() = 0;
    virtual ~AbstractClass() {};
};
#endif