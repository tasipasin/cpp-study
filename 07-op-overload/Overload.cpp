#include<iostream>
#include"Overload.h"

using namespace std;

Overload::Overload() : str{ nullptr } {
    str = new char[1];
    *str = '\0';
}
Overload::Overload(const char* value) : str{ nullptr } {
    if (nullptr == value) {
        Overload();
    }
    else {
        str = new char[strlen(value) + 1];
        strcpy(str, value);
    }
}
Overload::Overload(Overload& copy) : str{ nullptr } {
    Overload(copy.str);
}

Overload::Overload(Overload&& copy) : str{ copy.str } {
    copy.str = nullptr;
}

Overload::~Overload() {
    delete[] str;
}

Overload& Overload::operator=(const Overload& rhs) {
    cout << "Using l-value overload OP" << endl;
    if (this == &rhs) {
        return *this;
    }
    // Anything allocated in heap must be dealocated to overwrite
    // (avoid memory leak)
    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

Overload& Overload::operator=(Overload&& rhs) {
    cout << "Using r-value overload OP" << endl;
    if (this == &rhs) {
        return *this;
    }
    // Anything allocated in heap must be dealocated to overwrite
    // (avoid memory leak)
    delete[] this->str;
    // Steal the pointer from rhs
    str = rhs.str;
    // When rhs is out of scope, prevent to take it's value with him
    rhs.str = nullptr;
    return *this;
}

Overload Overload::operator-() const {
    char* buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < strlen(buff); i++) {
        buff[i] = tolower(buff[i]);
    }
    Overload result{ buff };
    delete[]buff;
    return result;
}
Overload Overload::operator+() const {
    char* buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < strlen(buff); i++) {
        buff[i] = toupper(buff[i]);
    }
    Overload result{ buff };
    delete[]buff;
    return result;
}

void Overload::display() {
    cout << str << " : " << strlen(str) << endl;
}

// Not an member function

bool operator==(const Overload& left, const Overload& right) {
    // Is friend of Overload
    return std::strcmp(left.str, right.str) == 0;
}

// Insertion operator
ostream& operator<<(ostream& os, const Overload& rhs) {
    os << rhs.str;
    return os;
}

// Extaction operator
istream& operator>>(istream& is, Overload& rhs) {
    char* buffer = new char[1000];
    is >> buffer;
    rhs = Overload{ buffer };
    delete[] buffer;
    return is;
}