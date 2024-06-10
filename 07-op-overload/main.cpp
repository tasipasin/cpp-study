#include<iostream>
#include "Overload.h"

using namespace std;

int main()
{
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
    return 0;
}
