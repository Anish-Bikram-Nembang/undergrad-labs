// 5. Create a class Person with data members name and age. Write a function to
// input and display the details and check if the person is eligible to vote
// (age ≥ 18).
#include <iostream>
#include <string>
class Person {
  std::string name; int age;
public:
  void input() { std::cin >> name >> age; }
  void display() const { std::cout << name << ' ' << age << ' ' << (age >= 18 ? "eligible" : "not eligible") << '\n'; }
};
int main() { Person person; person.input(); person.display(); }
