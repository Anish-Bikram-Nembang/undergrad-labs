// 5. Write an example to illustrate on “Constructors in Derived Classes”.
#include <iostream>
class Base { protected: int value; public: explicit Base(int v) : value(v) {} };
class Derived : public Base { int extra; public: Derived(int v, int e) : Base(v), extra(e) {} void display() const { std::cout << value << ' ' << extra << '\n'; } };
int main() { Derived object(10, 20); object.display(); }
