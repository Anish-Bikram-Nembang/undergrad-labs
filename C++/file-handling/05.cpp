// 5. Create an Employee class containing:
// Employee ID
// Name
// Department
// Salary
// Write a program to store multiple employee objects in a file and retrieve
// them later.
#include <fstream>
#include <iostream>
#include <string>
class Employee {
  int id;
  std::string name, department;
  double salary;

public:
  Employee() = default;
  Employee(int i, std::string n, std::string d, double s)
      : id(i), name(n), department(d), salary(s) {}
  void save(std::ofstream &out) const {
    out << id << ' ' << name << ' ' << department << ' ' << salary << '\n';
  }
  void display() const {
    std::cout << id << ' ' << name << ' ' << department << ' ' << salary
              << '\n';
  }
  bool load(std::ifstream &in) {
    return (bool)(in >> id >> name >> department >> salary);
  }
};
int main() {
  int count;
  std::cin >> count;
  std::ofstream out("employee_records.txt");
  for (int i = 0; i < count; ++i) {
    int id;
    std::string name, department;
    double salary;
    std::cin >> id >> name >> department >> salary;
    Employee(id, name, department, salary).save(out);
  }
  out.close();
  std::ifstream in("employee_records.txt");
  Employee employee;
  while (employee.load(in))
    employee.display();
}
