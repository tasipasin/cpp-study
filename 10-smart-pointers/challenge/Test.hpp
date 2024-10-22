#ifndef _TEST_H
#define _TEST_H
#include<string>
#include<iostream>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{ 0 } {
        cout << "\tTest constructor (" << data << ")" << endl;
    }

    Test(int data) : data{ data } {
        cout << "\tTest constructor (" << data << ")" << endl;
    }

    int get_data() const {
        return data;
    }

    ~Test() {
        cout << "\tTest destructor (" << data << ")" << endl;
    }
};

#endif