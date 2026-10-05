// 2. Create a class Employee with data members name, id, and salary. Write
// functions to input and display details for multiple employees using an array
// of objects.
#include <iostream>
#include <string>
class Employee {
  std::string name; int id; double salary;
public:
  void input() { std::cin >> name >> id >> salary; }
  void display() const { std::cout << name << ' ' << id << ' ' << salary << '\n'; }
};
int main() {
  int count; std::cin >> count;
  if (count < 0) return 1;
  Employee *employees = new Employee[count];
  for (int i = 0; i < count; ++i) employees[i].input();
  for (int i = 0; i < count; ++i) employees[i].display();
  delete[] employees;
}
