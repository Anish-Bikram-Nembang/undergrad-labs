// 4.You need to design a calculator that performs four basic arithmetic
// operations. You will write a program that takes two numbers as input from the
// user. It then displays a list of arithmetic operations. The user selects one
// operation and the program displays the result of the corresponding operation.
// The program should also display which of the two input numbers is greater and
// which is smaller. Use do-while loop.

#include <iostream>
#include <stdexcept>
float calculator(float a, float b, int option) {
  switch (option) {
  case 1:
    return a + b;
  case 2:
    return a - b;
  case 3:
    if (b == 0) {
      throw std::invalid_argument("Null division error");
    }
    return a / b;
  case 4:
    return a * b;
  default:
    throw std::invalid_argument("Invalid argument");
  }
}
int main(void) {
  float a, b;
  std::cout << "Enter a number: ";
  std::cin >> a;
  std::cout << "Enter another number: ";
  std::cin >> b;
  int option{0};
  while (option != 5) {
    std::cout << "What do you want to do?\n";
    std::cout << "1. add\t2. subtract\t3. divide\t4. multiply\t5. exit\n";
    std::cin >> option;
    if (option == 5) break;
    try {
      std::cout << "Result: " << calculator(a, b, option) << '\n';
    } catch (const std::exception &error) {
      std::cout << "Error: " << error.what() << '\n';
    }
  }
  return 0;
}
