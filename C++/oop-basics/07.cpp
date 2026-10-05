// 7. Create a class Student with name and roll. Use a static data member to
// count the total number of students created. Display the total number of
// students after creating multiple objects.
#include <iostream>
#include <string>
class Student {
  static int count; std::string name; int roll;
public:
  Student(std::string n, int r) : name(n), roll(r) { ++count; }
  static int total() { return count; }
};
int Student::count = 0;
int main() { Student a("A", 1), b("B", 2), c("C", 3); std::cout << Student::total() << '\n'; }
