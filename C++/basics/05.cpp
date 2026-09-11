// 5.Write a C++ program to calculate the area of rectangle, square using
// function overloading.

#include <iostream>
float area(float a) { return a * a; }
float area(float a, float b) { return a * b; }

int main(void) {
  char option;
  std::cout
      << "What do you want to calculate area of? \na. square\tb. rectangle\n";
  std::cin >> option;
  switch (option) {
  case 'a': {
    float a;
    std::cout << "Enter length of side: ";
    std::cin >> a;
    std::cout << "Area: " << area(a) << '\n';
    break;
  }
  case 'b':
    float a, b;
    std::cout << "Enter length: ";
    std::cin >> a;
    std::cout << "Enter breadth: ";
    std::cin >> b;
    std::cout << "Area: " << area(a, b) << '\n';
    break;
  default:
    std::cout << "Invalid option";
    return 1;
  }
  return 0;
}
