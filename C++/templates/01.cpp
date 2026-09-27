// 1. Write a C++ program using a function template findMax() that accepts two
// values and returns the greater value. Test the function with: Two integers
// Two floating-point numbers
// Two characters
// Requirement: Use a single function template instead of writing separate
// functions for each data type.

#include <iostream>

using namespace std;

template <typename T> T findMax(T a, T b) { return (a > b) ? a : b; }

int main(void) {
  cout << "For two integers 3, 4: \n";
  cout << "Max: " << findMax(3, 4) << '\n';

  cout << "For two floating-point numbers 5.0f, 9.0f: \n";
  cout << "Max: " << findMax(5.0f, 9.0f) << '\n';

  cout << "For two characters numbers a, g: \n";
  cout << "Max: " << findMax('a', 'g') << '\n';

  return 0;
}
