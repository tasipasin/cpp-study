#ifndef _SOME_OBJECT_H
#define _SOME_OBJECT_H
#include<string>
#include<iostream>
using namespace std;

class SomeObject {
    string name;
public:
    SomeObject(const string name) : name{ name } {
    }

    inline string getName() const {
        return this->name;
    }

    ~SomeObject() {
        cout << "Destructing SomeObject of: " << this->name << endl;
    }
};

#endif