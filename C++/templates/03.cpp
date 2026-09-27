// 3. Create a class template named Calculator that supports the following
// operations: Addition Subtraction Multiplication Division The class should
// work with different numeric data types such as int, float, and double.
// Exception requirement: Throw an exception when the user attempts to perform
// division by zero.
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T> class Calculator {
private:
  T a;
  T b;

public:
  Calculator(T x, T y) : a(x), b(y) {}
  T add() { return a + b; }
  T multiply() { return a * b; }
  T subtract() { return a - b; }
  T divide() {
    if (b == 0)
      throw std::runtime_error("0 Division error\n");
    return a / b;
  }
  void displayResults() {
    try {
      cout << "Addition: " << add() << '\n';
      cout << "Subtraction: " << subtract() << '\n';
      cout << "Multiplication: " << multiply() << '\n';
      cout << "Division: " << divide() << '\n';
    } catch (const std::runtime_error &e) {
      cerr << "\nError: " << e.what();
    }
  }
};

int main(void) {
  Calculator<int> c{3, 0};
  Calculator<double> cD{6.0, 5.0};
  cout << "For integers 3, 0\n";
  c.displayResults();
  cout << "For doubles 6.0, 5.0\n";
  cD.displayResults();
  return 0;
}
