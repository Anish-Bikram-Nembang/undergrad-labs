// 3.Write a program which takes two numbers as input from user and determines
// which is the larger of the two numbers. The Program should also tell which of
// the entered numbers is even or odd.
#include <iostream>

bool isEven(int num) { return (num % 2) == 0; }

int main(void) {
  int numA, numB;
  std::cout << "Enter two numbers: ";
  std::cin >> numA >> numB;
  int largerNum = numA > numB ? numA : numB;
  std::cout << "Larger number: " << largerNum << '\n';
  std::cout << "And it is" << (isEven(largerNum) ? "Even" : "Odd");
  return 0;
}
