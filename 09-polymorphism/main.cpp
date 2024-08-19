#include<iostream>
#include<vector>
#include "Base.h"
#include "SubBase.h"
#include "SiblingSubBase.h"
#include "SubSubBase.h"
#include "AbstractClass.h"
#include "ConcreteClass.h"
#include "InterfaceClass.h"
#include "People.h"

using namespace std;

void print_base_not_virtual(Base& bs) {
    cout << bs.display_not_virtual() << endl;
}

void print_base_virtual(Base& bs) {
    cout << bs.display_virtual() << endl;
}

int main() {
    {
        Base base;
        SubBase sub_base;
        SiblingSubBase sibling_sub_base;
        SubSubBase sub_sub_base;

        // All these are print their correspondent class value
        cout << "Base non virtual: " << base.display_not_virtual() << endl;
        cout << "SubBase non virtual: " << sub_base.display_not_virtual() << endl;
        cout << "SiblingSubBase non virtual: " << sibling_sub_base.display_not_virtual() << endl;
        cout << "SubSubBase non virtual: " << sub_sub_base.display_not_virtual() << endl;

        // Here, because the compiler use static binding by default and it
        // doesn't know what type the pointer is pointing to at runtime
        // So, it will call the Base::display_not_virtual()
        cout << endl << "[Function non virtual]" << endl;
        cout << "Base: ";
        print_base_not_virtual(base);
        cout << "SubBase: ";
        print_base_not_virtual(sub_base);
        cout << "SiblingSubBase: ";
        print_base_not_virtual(sibling_sub_base);
        cout << "SubSubBase: ";
        print_base_not_virtual(sub_sub_base);
        Base* p1 = new SubSubBase();
        cout << "pointer SubSubBase non virtual: " << p1->display_not_virtual() << endl;

        // Virtual
        cout << endl << "=== Virtual ===" << endl;
        cout << "[Function virtual]" << endl;
        cout << "Base: ";
        print_base_virtual(base);
        cout << "SubBase: ";
        print_base_virtual(sub_base);
        cout << "SiblingSubBase: ";
        print_base_virtual(sibling_sub_base);
        cout << "SubSubBase: ";
        print_base_virtual(sub_sub_base);

        // Base Class Pointer
        cout << endl << "=== Base Class Pointer ===" << endl;
        Base* p2 = new Base();
        Base* p3 = new SubBase();
        Base* p4 = new SiblingSubBase();

        vector<Base*> base_vector{ p2, p3, p4, p1 };
        for (auto base_item : base_vector) {
            cout << "not virtual: " << base_item->display_not_virtual() << endl;
            cout << "virtual: " << base_item->display_virtual() << endl;
        }
        cout << "Deleting p1" << endl;
        delete p1;
        cout << "Deleting p2" << endl;
        delete p2;
        cout << "Deleting p3" << endl;
        delete p3;
        cout << "Deleting p4" << endl;
        delete p4;

        cout << "Ending deleting" << endl;
    }

    cout << endl;
    // Base class reference
    {
        cout << "[Base class reference]" << endl;
        SiblingSubBase sibling_sub_base;
        Base& base = sibling_sub_base;
        cout << "sibling_sub_base.display_virtual(): " << sibling_sub_base.display_virtual() << endl;
        cout << "base.display_virtual(): " << base.display_virtual() << endl;

    }

    cout << endl;

    // Abstractions
    {
        cout << "[Abstraction]" << endl;
        // Next line doesn't compile because can't instantiate an Abstract Class
        // AbstractClass ac;

        // Both works because cc is defined from a concrete class
        // and aci is defined as something that is an abstract class
        // but it is initialized as concrete class
        ConcreteClass cc;
        cc.abstract();
        AbstractClass* aci = new ConcreteClass();
        aci->abstract();
        delete aci;

    }

    cout << endl;

    // Abstract Classes as Interface
    {
        cout << "[Abstract Classes as Interface]" << endl;
        InterfaceClass* ic = new People();
        // Do not forget do dereference
        cout << "InterfaceClass new People: " << *ic << endl;
        delete ic;
    }

    return 0;
}