#include "Person.h"
#include "PersonAddressBuilder.h"
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include <iostream>

using namespace std;

int main(void) {
    Person me = Person::create()
                    .lives()
                    .at("6 October")
                    .with_postcode("15951")
                    .in("Giza")
                    .works()
                    .at("707")
                    .as_a("Programmer")
                    .earning(536);
    cout << &me << endl;

    // ? Why there is 2 person have been destroyed?
    // Because there is 2 Person P and me
}