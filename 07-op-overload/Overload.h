#ifndef _OVERLOAD_H_
#define _OVERLOAD_H_
#include<cstring>

class Overload {
private:
    char* str;
public:
    Overload();
    Overload(const char* value);
    // Works for l-values
    Overload(Overload& copy);
    // Works for r-values
    Overload(Overload&& copy);
    ~Overload();

    /**
     * Assignment operator overload (Works with l-value references)
     * Not temp value beeing used to do the assignment
     * @param rhs The parameter on the right hand side
    */
    Overload& operator=(const Overload& rhs);

    /**
     * Assignment operator overload (Works with r-value references)
     * Temp values beeing used to do the assignment
     * Not const because it will lose it's pointer ie. it's gonna be modified
     * @param rhs The parameter on the right hand side
    */
    Overload& operator=(Overload&& rhs);

    /**
     * Returns a NEW object in lowercase
     * Operates on itself
     * @return A new object with the string attribute in lowercase
    */
    Overload operator-() const;

    /**
     * Returns a NEW object in uppercase
     * Operates on itself
     * @return A new object with the string attribute in uppercase
    */
    Overload operator+() const;

    void display();
};

#endif