// 3. Create a base class Animal with a virtual function speak(). Derive two
// classes Dog and Cat that override the speak() method. Demonstrate runtime
// polymorphism using a base class pointer.
#include <iostream>
class Animal { public: virtual void speak()const=0; virtual ~Animal()=default; };
class Dog:public Animal{public:void speak()const override{std::cout<<"Woof\n";}};
class Cat:public Animal{public:void speak()const override{std::cout<<"Meow\n";}};
int main(){Dog dog;Cat cat;Animal*animals[]={&dog,&cat};for(auto animal:animals)animal->speak();}
