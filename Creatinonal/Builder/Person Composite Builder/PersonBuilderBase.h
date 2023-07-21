#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
  protected:
    Person &person;
    explicit PersonBuilderBase(Person &person) : person{person} {
        cout << "PersonBuilderBase ctor, " << &person << endl;
    }

  public:
    operator Person() const { return std::move(person); }

    // builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};