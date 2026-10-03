// 1. Write a program to enter a number and perform ciel() and floor function to
// obtain the rounded values
// 2. Write a program to define the UDF
// a. To calculate the factorial
// b. To generate a fibonacci series upto 'n' term [recursive function]

#include <iostream>
using namespace std;

int fact(int num) {
  if (num < 0)
    return -1;
  if (num == 1 || num == 0)
    return 1;
  return num * fact(num - 1);
}

int fibo(int n) {
  if (n <= 1)
    return n;
  return fibo(n - 1) + fibo(n - 2);
}

int main(void) {
  int num;
  cout << "Enter a number: " << endl;
  cin >> num;
  cout << "Factorial of " << num << ": " << fact(num) << endl << endl;
  cout << "Enter the number of terms" << endl;
  cin >> num;
  cout << "Fibonacci Series: " << endl;
  for (int i = 0; i < num; i++) {
    cout << fibo(i);
    if (i < num - 1)
      cout << ", ";
  }
  return 0;
}
