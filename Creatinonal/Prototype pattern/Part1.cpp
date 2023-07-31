// * Prototype Pattern

// it is a Creational Design Pattern
// it allows creating new object by cloning existing ones
// it clones a pre-existing object and modify it as needed
// it is useful when the cost of creating object is high

// to build objects from scratch {Factories and Builders will help}
// to modify existing one {prototype will help}

// ! Ordinary Duplication:
#include <iostream>
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
    Address address;

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "Name: " << contact.name << " Address: " << contact.address.street
           << ", " << contact.address.city << ", " << contact.address.suite
           << "\n";
        return os;
    }
};

Contact worker{"", Address{"123 East", "London", 0}};

// int main(void) {
//     Contact john{worker}; // Remember Rule of '0'
//     john.name = "John";
//     john.address.suite = 13;

//     cout << john << endl;
// }

// ! But the duplication is done by value {higher cost for complex object}
// How to do it by ref or by ptr

// convert the contact class to be like that
// but we will need the copy constructors for both the classes

class Address1 {
  public:
    string street, city;
    int suite;

    // ToDo: Remember rule of'5'
    Address1(string s, string c, int su) : street{s}, city{c}, suite{su} {}

    // ! Adding the copy constructor
    Address1(const Address1 &RHS) {
        this->city = RHS.city;
        this->street = RHS.street;
        this->suite = RHS.suite;
    }
};

class Contact1 {
  public:
    string name;
    Address1 *address; // TODO: it is better to use smart pointer instead of
                       // TODO: this raw pointer

    virtual ~Contact1() { delete address; };

    // ToDo: Remember rule of'5'
    Contact1(string n, Address1 *a) : name{n}, address{a} {}

    // ! Adding the copy constructor
    Contact1(const Contact1 &RHS)
        : name{RHS.name}, address{new Address1{*RHS.address}} {}

    friend ostream &operator<<(ostream &os, const Contact1 &contact) {
        os << "Name: " << contact.name
           << " Address: " << contact.address->street << ", "
           << contact.address->city << ", " << contact.address->suite << "\n";
        return os;
    }
};

Contact1 worker1{"", new Address1{"123 East", "London", 0}};

int main(void) {
    Contact1 john{worker1}; // Remember Rule of '5'
    john.name = "John";
    john.address->suite = 13;

    cout << john << endl;
}

// ! note that
// contact john = worker; then copy assignment operator is needed
// contact john {worker}; then copy constructor is needed
