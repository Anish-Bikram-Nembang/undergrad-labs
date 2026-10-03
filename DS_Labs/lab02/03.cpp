// 1. Write a program to enter a number and perform ciel() and floor function to
// obtain the rounded values
// 2. Write a program to define the UDF
// a. To calculate the factorial
// b. To generate a fibonacci series upto 'n' term [recursive function]
// 3. Write a program to evaluate the power function for different values of 'x'
// and 'n' (n -> const value)
#include <iostream>
using namespace std;

float power(int x, int n) {
  float result = 1.0;
  if (n == 0) {
    return 1;
  }
  if (n > 0) {
    for (int i = 0; i < n; i++) {
      result *= x;
    }
    return result;
  } else {
    for (int i = 0; i < -n; i++) {
      result /= x;
    }
    return result;
  }
}
int main(void) {
  double x, n;
  cout << "Enter a number" << endl;
  cin >> x;
  cout << "Enter power" << endl;
  cin >> n;
  float pow = power(x, n);
  cout << x << "^" << n << " = " << pow << endl;
  return 0;
}

// 1. Write a program to enter a number and perform ciel() and floor function to
// obtain the rounded values
// 2. Write a program to define the UDF
// a. To calculate the factorial
// b. To generate a fibonacci series upto 'n' term [recursive function]
// 3. Write a program to evaluate the power function for different values of 'x'
// and 'n' (n -> const value)
// 4. Write a program to generate an arithmetic series and geometric series upto
// nth term as entered by a user
// 5. Write a program to estimate the value of f(x) for any provided 'x' using
// the following table
//   | x | 1 | 2 | 3 | 4 | 5 |
//   |f(X)| 1 | 1.9192 | 1.7321 | 2 | 2.2361 |
