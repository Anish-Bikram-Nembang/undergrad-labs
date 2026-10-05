// 9. Write a C++ program to check whether a given year is leap year or not.
#include <iostream>
int main() {
  int year;
  std::cin >> year;
  std::cout << (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
                    ? "Leap year\n" : "Not a leap year\n");
}
