// 7.Write a C++ program to demonstrate parameter passing mechanism using pass
// by address method.
#include <iostream>

void tryToManipulateData(int *number) {
  // original is change because parameter is passed by address and accessed by
  // dereferencing
  (*number)++;
}

int main(void) {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;

  std::cout << "Trying to increment by 1...\n";
  tryToManipulateData(&number);
  std::cout << "Entered number: " << number << '\n';

  return 0;
}
// write a function to print hello world
void printHello() {}
