// 4. Use an array of base class pointers to store Animal objects and
// demonstrate polymorphic behavior when calling speak().
#include <iostream>
class Animal { public: virtual void speak()const=0; virtual ~Animal()=default; };
class Dog:public Animal{public:void speak()const override{std::cout<<"Woof\n";}};
class Cat:public Animal{public:void speak()const override{std::cout<<"Meow\n";}};
int main(){Animal*animals[]={new Dog,new Cat};for(auto animal:animals){animal->speak();delete animal;}}
