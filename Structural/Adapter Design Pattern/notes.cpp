// * Adapter Design Pattern

// Adapter is a Structural Design Pattern

// sometimes, the abstraction provided by a class doesn't suit the current
// design so we start using the adapter design pattern

// So, you are given an interface but you want a different one, so Build an
// Adapter

// it seems as a bridge between the desired abstraction and the actual code

// There are 2 use cases:
// 1-   Implementing a certain interface by using some existing implementation.
//      so, the adapter pattern typically creates an instance of implementation
//      behind the scene

//  2-  Allowing existing functionality to be used through a new interface.
//      in this use case, the constructor of the adapter typically receives an
//      instance of the underlying object in the constructor

// ! standard library uses the adapter pattern to implement containers like
// ! stack and queue in terms of other containers such as deque and list

// * Summery:
//  Adapter is a very simple concept. It helps us adapt an interface to the
//  interface you need.
//  you need to ensure that you use laziness -> converting is done only when
//  required
