// 4. Write a program to generate an arithmetic series and geometric series upto
// nth term as entered by a user

#include <cmath>
#include <iostream>
using namespace std;

void generateArithmeticSeries() {
  double a, d, n;
  cout << "Enter first term: " << endl;
  cin >> a;
  cout << "Enter common difference: " << endl;
  cin >> d;
  cout << "Enter number of terms to generate: " << endl;
  cin >> n;
  cout << "Arithmetic series: ";
  for (int i = 0; i < n; i++) {
    cout << a + i * d;
    if (i != n - 1)
      cout << ", ";
  }
  cout << endl;
}
void generateGeometricSeries() {
  double a, r, n;
  cout << "Enter first term: " << endl;
  cin >> a;
  cout << "Enter common ratio: " << endl;
  cin >> r;
  cout << "Enter number of terms to generate: " << endl;
  cin >> n;
  cout << "Geometric series: ";
  for (int i = 0; i < n; i++) {
    cout << a * pow(r, i);
    if (i != n - 1)
      cout << ", ";
  }
  cout << endl;
}

int main(void) {
  generateArithmeticSeries();
  generateGeometricSeries();
  return 0;
}
