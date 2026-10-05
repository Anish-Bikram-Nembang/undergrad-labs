// 1. Create a class Student with data members name, roll, and marks. Write
// member functions to input and display the data of a student.
#include <iostream>
#include <string>
class Student {
  std::string name; int roll; float marks;
public:
  void input() { std::cin >> name >> roll >> marks; }
  void display() const { std::cout << name << ' ' << roll << ' ' << marks << '\n'; }
};
int main() { Student student; student.input(); student.display(); }
