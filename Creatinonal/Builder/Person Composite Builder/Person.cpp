#include "Person.h"
#include "PersonBuilder.h"


// note that the create static [[nodiscard method]] return the Person Builder
PersonBuilder Person::create() { return PersonBuilder{}; }