// * Singleton Design Pattern
// It is a simple Creational Design Pattern
// "Singleton" in English means "one of a kind" or "individual"
//! The most hated Design pattern and Avoid use it in new code

// It is used when you  should only have one instance of a particular component
// in your application for example => you may need only one database or one
// logger in your code

// Applying singleton pattern to an object make people refer to it by a
// singleton class.
// as this pattern guarantees that only oen object of that class will ever be
// created

// You may make the single object as a global static variable in your code, but
// this is not recommended as it always in the memory even if we don't need it

// One way to coerce the client to only has one singleton element is to hide the
// constructor and make get method that return the same singleton element each
// time

// This technique is thread-safe since C++11, if 2 threads call get
// simultaneously that is safe and the object won't be created twice

// Example
// I only have the ability to have only one instance from the database class
class Database {
  protected:
    // note that the constructor is hidden
    Database() {}

  public:
    // The only way to instantiate an element from that element
    static Database &get(void) {
        static Database database;
        return database;
    }
    Database(const Database &) = delete;
    Database(const Database &&) = delete;
    Database operator=(const Database &) = delete;
    Database operator=(const Database &&) = delete;
};

// Singleton per thread is available by changing the previous get method to be
// as following
#include "thread"

class DataBase {
  protected:
    // note that the constructor is hidden
    DataBase() {}

  public:
    // The only way to instantiate an element from that element
    static DataBase &get() {
        thread_local DataBase instance;
        return instance;
    }
    DataBase(const DataBase &) = delete;
    DataBase(const DataBase &&) = delete;
    DataBase operator=(const DataBase &) = delete;
    DataBase operator=(const DataBase &&) = delete;
};

// * Monostate
// it is a class that behaves like a singleton but it is appearing as an
// ordinary class

// it is easy and simple for implementation no extra code is needed
// ability to inherit and leverage polymorphism
// you have the ability to instantiate many elements and the system will work
// properly

// but note that: it is not easy to convert an ordinary class to a monostate
// class

// using a static data means it is always take the space in memory even when it
// is not needed

// Example
class printer {
    static int id;

  public:
    int getID(void) const { return id; }
    void setID(int val) { id = val; }
};
// This class only has static data
// so, all objects will be identical

// ! very important note =>
// ! if all methods on a class are static then this class will never be created

// ! Disadvantages of Singleton Pattern
//  - if you have many singleton on your code, there is nothing guarantees that
//    they are initialized in the right order
//  - singleton classes introduce hidden dependencies cause tight coupling and
//    complicate the unit testing

// So, you need to use it carefully

// ToDo: see the logger Example into the logger files
// This logger is=>
// - available at all the time.
// - easy to use.
// - only one instance.