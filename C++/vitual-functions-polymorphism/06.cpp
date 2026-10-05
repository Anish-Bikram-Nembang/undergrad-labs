// 6. Demonstrate the need for a virtual destructor. Create a base class Base
// and a derived class Derived. Allocate memory dynamically and delete the
// object through a base class pointer. Observe the difference with and without
// a virtual destructor.
#include <iostream>
class Base{public:virtual~Base(){std::cout<<"Base destructor\n";}};
class Derived:public Base{public:~Derived()override{std::cout<<"Derived destructor\n";}};
int main(){Base*object=new Derived;delete object;}
