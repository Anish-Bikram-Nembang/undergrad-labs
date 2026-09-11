// 1.Write a temperature conversion program that gives the user the option of
// converting a value of temperature to Celsius and Fahrenheit scales of
// temperature.
#include <iostream>

int main(void) {
  int option;
  std::cout << "What do you want to do?\n1. Convert Fahrenheit to Celsius\t2. "
               "Convert Celsius to Fahrenheit\n";
  std::cin >> option;
  switch (option) {
  case 1: {
    float celsius, fahrenheit;
    std::cout << "Enter temperature in celsius: ";
    std::cin >> celsius;
    fahrenheit = celsius * 9.0f / 5.0f + 32;
    std::cout << "Fahrenheit: " << fahrenheit << '\n';
  }
  case 2: {
    float celsius, fahrenheit;
    std::cout << "Enter temperature in fahrenheit: ";
    std::cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5.0f / 9.0f;
    std::cout << "Celsius: " << celsius << '\n';
  }
  default:
    std::cout << "Invalid option";
  }
  return 0;
}
