#pragma once
#include "Person.h"
#include "PersonBuilderBase.h"
#include <iostream>

using namespace std;

class PersonBuilder : public PersonBuilderBase {
    Person p;

  public:
    PersonBuilder() : PersonBuilderBase{p} {
        cout << "PersonBuilder ctor" << endl;
    }
};