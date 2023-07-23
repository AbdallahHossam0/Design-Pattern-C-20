#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
  protected:
    Person &person;   // this a ref to the object being build by the builder {person p} on the person builder


    // protected constructor (so, only the PersonAddressBuilder and PersonJobBuilder can use this constructor)
    explicit PersonBuilderBase(Person &person) : person{person} {
        cout << "PersonBuilderBase ctor, " << &person << endl;
    }

  public:
  // to be able to use that {move constructor} should be defined in the person class
    operator Person() const { return std::move(person); }
    // this the conversion operator (convert the personbuilderbaseobject to person object)

    // builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};