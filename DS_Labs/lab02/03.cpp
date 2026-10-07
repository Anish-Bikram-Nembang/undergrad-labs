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
