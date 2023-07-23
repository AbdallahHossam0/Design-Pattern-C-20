#include "Person.h"
#include "PersonAddressBuilder.h"
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include <iostream>

using namespace std;

int main(void) {
    Person me = Person::create() // this line returns (person builder object) then it is converted to person base object that has lives and works
                    .lives() // this line returns the person address builder
                    .at("6 October")
                    .with_postcode("15951")
                    .in("Giza")
                    .works()    // this line returns the person job builder
                    .at("707")
                    .as_a("Programmer")
                    .earning(536);
    
    cout << &me << endl; // this ability by defineing the friend ofstream in the class builder

    // ? Why there is 2 person have been destroyed?
    // Because there is 2 Person P and me
}