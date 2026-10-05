/*
 * 1. What is Inheritance?
 *  => Inheritance is an object oriented programming feature
 *  that lets a new class acquire (inherit) the features and behaviours
 *  of an existing class
 *
 * What are the advantages of Inheritance?
 * => Code reusability, reduce code duplication, allow for polymorphism
 * and extensibility
 */

// What are the different types of Inheritance ? Explain with examples.

#include <iostream>

// Single inheritance: One derived class inherits from one base class.
class Animal {
public:
  void eat() { std::cout << "Eating\n"; }
};
class Mammal : public Animal {
public:
  void walk() { std::cout << "Walking...\n"; }
};

// Multiple inheritance: One derived class inherits from multiple base classes.
class Cpu {
public:
  void execute() { std::cout << "Executing\n"; }
};
class Keyboard {
public:
  void write() { std::cout << "Writing\n"; }
};
class Laptop : public Cpu, public Keyboard {};

// Multilevel inheritance: occurs in multiple level, taking the previous animal
// -> mammal relationship and adding a dog class.
class Dog : public Mammal {
public:
  void bark() { std::cout << "Woof!\n"; }
};

// Hierarchical inheritane: Multiple derived classes inherit from the same base
// class, again taking the mammal -> dog class relationship and adding cats.
class Cat : public Mammal {
public:
  void meow() { std::cout << "Meow~\n"; }
};

// Hybrid Inheritance: combination of one or more types of inheritance.
class Pet : public Dog, public Cat {};
int main() {
  Dog dog; dog.eat(); dog.walk(); dog.bark();
  Laptop laptop; laptop.execute(); laptop.write();
}
