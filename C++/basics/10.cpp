// 10. Write a C++ program to find the factorial of a given number
#include <iostream>
int main() {
  unsigned int n;
  std::cin >> n;
  unsigned long long result = 1;
  for (unsigned int i = 2; i <= n; ++i) result *= i;
  std::cout << n << "! = " << result << '\n';
}
