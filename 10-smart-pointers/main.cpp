#include <memory>
#include <iostream>
#include "SomeObject.hpp"

using namespace std;

void custom_smart_pointer_deleter(SomeObject* ptr) {
    cout << "Hello, I'm the custom_smart_pointer_deleter()" << endl;
    delete ptr;
}

int main() {
    // Smart pointer helps to be more clear
    // about who owns the pointer and when a pointer
    // should be deleted to free some memory

    // Smart pointers are objects that can only point to heap
    // allocated memory and automatically call delete when
    // it's not needed anymore

    // Unique Pointers
    {
        cout << "[Unique Pointers]" << endl;
        // unique_ptr<T>
        // Very efficient
        // Points to an object of Type T
        // It's unique. There can be only one pointer pointing to
        // the object on the heap
        // Owns what it points to
        // Cannot be copied or assigned, but can be moved
        // When the pointer is destroyed, what it points to is
        // automatically destroyed
        unique_ptr<SomeObject> ptr{ new SomeObject("Tasi") };
        cout << "Object pointer to getName(): " << ptr->getName() << endl;
        cout << "Pointed to address: " << ptr.get() << endl;

        if (ptr) {
            cout << "I'm still here" << endl;
        }
        // Descontructor from SomeObject will be called
        ptr.reset();
        if (ptr) {
            // This won't be showed
            cout << "Not here anymore :(" << endl;
        }

        cout << "-- Since C++14" << endl;
        // No calls of new or delete
        unique_ptr<SomeObject> ptr2 = make_unique<SomeObject>("Other Object");
        cout << "ptr2 name: " << ptr2->getName() << endl;
        auto ptr3 = make_unique<SomeObject>("Autoed");
        cout << "ptr3 name: " << ptr3->getName() << endl;
    }

    cout << endl;

    // Shared Pointers
    {
        cout << "[Shared Pointers]" << endl;
        // It's more efficient
        // Many pointer can point to the same object on the heap
        // Can be assigned, copied and moved
        // When the count of Pointer to the object on the heap is zero,
        // the object is destroyed
        shared_ptr<SomeObject> shared1{ new SomeObject{ "SharedObject" } };
        cout << "shared1: " << shared1->getName() << endl;
        cout << "shared1 use_count: " << shared1.use_count() << endl;
        {
            // Shares the pointer to the heap object
            auto shared2{ shared1 };
            cout << "shared2: " << shared2->getName() << endl;
            cout << "shared1 use_count: " << shared1.use_count() << endl;
            cout << "shared2 use_count: " << shared2.use_count() << endl;
        } // Ends of shared2 scope
        cout << "shared1 use_count: " << shared1.use_count() << endl;
        // The shared use_count become 0, so the the object must be automatically deallocated
        shared1.reset();
        cout << "shared1 use_count: " << shared1.use_count() << endl;
    }

    cout << endl;

    // Weak Pointers
    {
        cout << "[Weak Pointers]" << endl;
        // A weak pointer points to an object on the heap
        // but it doesn't count to owning relationship
        // Can be created from shared pointers to temporarily
        // visits the object pointed to
    }

    cout << endl;

    // Custom Deleters
    {
        cout << "[Custom Deleters]" << endl;
        // Smart pointers allows to provide custom deleters
        // used in special use-cases that destroying the object
        // on the heap
        shared_ptr<SomeObject> shared{ new SomeObject("Using Custom Deleter"),
        custom_smart_pointer_deleter };
        // Should show the delete message by passing the custom function
        shared.reset();

        // Using lambda expression (cool)
        // Lambda is an anonymous function that has no name and can be defined
        // right where it's will be used
        shared_ptr<SomeObject> shared_lambda(new SomeObject("For lambda!"),
            [](SomeObject* ptr) {
                cout << "Custom deleter using lambda" << endl;
                delete ptr;
            });
        // Should show the delete message by passing the custom function
        shared_lambda.reset();
    }
    return 0;
}