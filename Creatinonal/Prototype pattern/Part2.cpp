// * Prototype Factory

// you can use the prototype as a global variable or as a prototype factory as
// following
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Address {
  public:
    string street, city;
    int suite;
};

class Contact {
  public:
    string name;
    Address *address;

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "Name: " << contact.name
           << " Address: " << contact.address->street << ", "
           << contact.address->city << ", " << contact.address->suite << "\n";
        return os;
    }
};

class EmployeeFactory {
  public:
    static Contact mainEmp;
    static Contact auxEmp;

  private:
    static unique_ptr<Contact> NewEmployee(string name, int suite,
                                           Contact &proto) {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->address->suite = suite;
        return result;
    }

  public:
    static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite) {
        // static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
        return NewEmployee(name, suite, mainEmp);
    }

    static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite) {
        return NewEmployee(name, suite, auxEmp);
    }
};

Contact EmployeeFactory::mainEmp{"", new Address{"123 East Dr", "London", 0}};
Contact EmployeeFactory::auxEmp{"", new Address{"123B East Dr", "London", 0}};

int main(void) {
    auto john{EmployeeFactory::NewAuxOfficeEmployee("John", 13)};
    auto jane{EmployeeFactory::NewMainOfficeEmployee("Jane", 19)};

    cout << *john << *jane;
}
