// Builder Design pattern

// used 'ONLY' to create "Complicated Objects"
// it is a 'Creational Design Pattern'

// Fluent Builders
//  returning a reference or a pointer to the builder itself. the builder calls can now be chained. {Fluent Interface}
//  Example

class builder{
    int m_x, m_y;
    public:
        builder* add_x(int x){
            m_x = x;
            return this;
        }
        builder& add_y(int y){
            m_y = y;
            return *this;
        }
};

int main(void){
    // This builder can be chained as following 
    builder b1, b2;

    // note the difference between retrunning this or *this ^^

    b1.add_x(5)->add_y(7);

    b2.add_y(7).add_x(5);

    return 0;
}
// ? How to force the lient to use builders??
// * this can be done by makring the object constructors {private (static [[no discard]] build method will be used) or protected (inheritance will be used)}


// * Composite builders 
// multiple builers will be used to build up a single object {this can be used for complicated objects that has complicated members}

// note the use of the conversion operator
// that helps us to cast the builder to the object directly 

// ! Summery
// builders should be fluent (have the ability to chain)
// you should force the client to use the builder by making all constructors inaccessible
// remeber to use the conversion operator inside the builder 
// remeber to use composite builders for very complex and complicated objects

