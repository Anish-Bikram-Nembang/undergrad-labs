// 8. Write a C++ program to reverse a given number.

#include <iostream>
int reverseNumber(int number) {
  int reversed = 0;
  bool negative = number < 0;
  if (negative) number = -number;
  do { reversed = reversed * 10 + number % 10; number /= 10; } while (number);
  return negative ? -reversed : reversed;
}
int main(void) {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  std::cout << "Reversed number: " << reverseNumber(number) << '\n';
}
