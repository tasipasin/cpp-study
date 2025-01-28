#ifndef _DERIVED_EXCEPTION_H
#define _DERIVED_EXCEPTION_H

class DerivedException : public std::exception {
public:
    // The "noexcept" tells this method/constructor can't throw an exception
    DerivedException() noexcept = default;
    // The destructor is "noexcept" by default
    ~DerivedException() = default;

    // Virtual method provided by the exception class
    virtual const char* what() noexcept {
        return "I'm a Derived Exception";
    }
};
#endif