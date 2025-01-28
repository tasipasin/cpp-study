#ifndef __INSUFFICENT_FUNDS_EXCEPTION_H__
#define __INSUFFICENT_FUNDS_EXCEPTION_H__

class InsufficentFundsException: public std::exception
{
public:
    InsufficentFundsException() {}
    ~InsufficentFundsException() {}
    virtual const char* what() const noexcept {
        return "Not enough funds to realize operation.";
    }
};

#endif // __INSUFFICENT_FUNDS_EXCEPTION_H__