// * Factories Design patterns

// it is a Creational Design Patterns which is usually used to put constrains on object constructions
// it is creating the object on one go not like builder piecewise

// * Factories on OOP constructs Objects

// There are many types of factories : but the most popular are those
// * 1- Factory Method
// * 2- Abstract Factory
// * 3- Functional Factory

// 1- Factory Method 
//  is a class member {method} that is used to for creating the object
// instead of putting the validation on the constructor you can make a method that can create the object and
// validate it and return it in case the object passed the validation or return nullptr otherwise

// the factory method should be static 
// we also have the ability to return the object by value or a pointer [raw or smart] pointing to the object in free space memory

// as you are now using the factory method it is recommended to hide the constructor and now the client should using the factory methods
// hide it means [make it private if your class is marked as {final} or make it protected otherwise]


// ! Don't make your constructor private nad male the function or the class using it {friend}
// ! as this is a clear violation for OCP


// * note that the polymorphic Factory Methods that help us to create the object and all its derived object on one method 


// 2- Abstract Factory is not common and usually used in very complicated systems
// separate class that know how to construct objects

// 3- Functional Factory
// Functional factory is a function when called creates an object

// Here is a functional factory
#include <functional>
class T;
T f(void);
void construct(std::function<T()> f){
    T t{f()};
}

// ! here f is a Functional factory


// * Benefits of Factories
// 1- Ability to track all objects that have been constructed 
// 2- you don't need to know the exact type of the object you are creating.
// 3- Factories are helpful for creating objects that require comp;ex series of steps to be executed in a certain order
// 4- A factory can do validations and return std::optional<T> to return null if the object didn't pass the validation 
// 5- A factory method can be polymorphic {it also can return std::variant}


// ! Factories is different from builder
// * Factory => the object is created in one go
// * Builder => the object is constructed piecewise by providing information by parts
