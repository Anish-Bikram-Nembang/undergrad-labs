// 2. Create a function template that accepts an array and its size and performs
// the following operations: Display all elements Find the largest element Find
// the smallest element Calculate the sum of elements Test the template using
// arrays of int, float, and double.

#include <iostream>
using namespace std;
template <typename T> void processArray(T *arr, size_t size) {
  T smallest{arr[0]};
  T largest{arr[0]};
  T sum{arr[0]};

  cout << "elements: \n";
  cout << arr[0];
  for (size_t i = 1; i < size; i++) {
    cout << ", " << arr[i];
    if (arr[i] > largest)
      largest = arr[i];
    if (arr[i] < smallest)
      smallest = arr[i];
    sum += arr[i];
  }
  cout << "\nLargest element: " << largest << '\n';
  cout << "Smallest element: " << smallest << '\n';
  cout << "Sum:" << sum << '\n';
}

int main(void) {
  int arrI[]{1, 2, 3, 4, 5};
  float arrF[]{6, 5, 4, 2, 4};
  double arrD[]{9, 4, 3, 2, 1};

  cout << "\nUsing integers: \n";
  processArray(arrI, 5);

  cout << "\nUsing floats: \n";
  processArray(arrF, 5);

  cout << "\nUsing doubles: \n";
  processArray(arrD, 5);

  return 0;
}
