#include<iostream>
#include "Overload.h"
#include "Money.h"

using namespace std;

int main()
{
    cout << "Overload operator as class members" << endl;
    /** Copy (l-value) */
    {
        cout << "Copy (l-value)" << endl;
        Overload original{ "Tasi" };
        Overload aCopy;
        cout << "Before assign" << endl;
        cout << "original: "; original.display();
        cout << "aCopy: "; aCopy.display();
        // Under the sheets, will call aCopy.operator=(const Copy& rhs)
        aCopy = original;
        cout << "After assign" << endl;
        cout << "original: "; original.display();
        cout << "aCopy: "; aCopy.display();
        original = "New Value";
        cout << "Attributing a new value to original" << endl;
        cout << "original: "; original.display();
        cout << "aCopy: "; aCopy.display();
    }

    /** Copy (r-value) */
    {
        cout << "Copy (r-value)" << endl;
        Overload original{ "Tasi" };
        cout << "original: "; original.display();
        original = Overload{ "Monday comes around" };
        cout << "original (monday): "; original.display();
        original = "Learning to Breath";
        cout << "original (Breath): "; original.display();
    }

    /** Others */
    {
        cout << "Upper and Lower" << endl;
        Overload strange{ "I'M aLtErNaTiNg" };
        cout << "original: "; strange.display();
        cout << "lowercase: "; (-strange).display();
        cout << "uppercase: "; (+strange).display();
    }

    cout << endl;

    /** Test */
    {
        cout << "================" << endl;
        cout << "Money Test" << endl;
        Money m1{ 159 };
        Money m2{ 1, 59 };
        Money m3{ 250 };
        cout << boolalpha;
        cout << "m1 == m2: " << (m1 == m2) << endl;
        cout << "m1 == m3: " << (m1 == m3) << endl;
        cout << "m2 == m3: " << (m2 == m3) << endl;
        cout << "m1 != m2: " << (m1 != m2) << endl;
        cout << "m1 != m3: " << (m1 != m3) << endl;
        cout << "m2 != m3: " << (m2 != m3) << endl;
    }

    cout << "Overload operator as global functions" << endl;
    {
        Overload right{ "Tasi" };
        Overload left{ "Pasin" };
        Overload leftRepeat;
        leftRepeat = right;
        cout << "right == left: " << (right == left) << endl;
        cout << "right == leftRepeat: " << (right == leftRepeat) << endl;
        cout << "left == leftRepeat: " << (left == leftRepeat) << endl;
    }

    /** Test */
    {
        cout << "================" << endl;
        cout << "Money Test Non-Member" << endl;
        Money m1{ 159 };
        Money m2{ 2,30 };
        int expectedResult = m1.get_cents() + m2.get_cents() + ((m1.get_dollars() + m2.get_dollars()) * 100);
        Money m3 = m1 + m2;
        cout << "m1 + m2 = " << m3.get_cents() + (m3.get_dollars() * 100) << endl;
        cout << "expected value: " << expectedResult;

    }

    cout << endl << endl;

    /** Stream operators */
    {
        cout << "================" << endl;
        cout << "Overload Stream Operators" << endl;
        Overload firstName;
        cout << "Enter first name:";
        cin >> firstName;
        cout << "Name entered: " << firstName;
    }

    /** Test */
    {
        cout << "================" << endl;
        cout << "Money Test Overload Stream Operatorsr" << endl;
        Money m1{ 1,70 };
        cout << m1;
    }
    return 0;
}
