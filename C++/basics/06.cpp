// 6.Write a C++ program to demonstrate parameter passing mechanism using pass
// by value method.

#include <iostream>

void tryToManipulateData(int number) {
  // original is left unchanged since parameter is passed by value
  (void)++number;
}

int main(void) {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;

  std::cout << "Trying to increment by 1...\n";
  tryToManipulateData(number);
  std::cout << "Entered number: " << number << '\n';

  return 0;
}
