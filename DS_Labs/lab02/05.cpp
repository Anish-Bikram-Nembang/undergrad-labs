#include <iostream>
using namespace std;

double linearInterpolation(double x, double x1, double y1, double x2,
                           double y2) {
  return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
}

int main() {
  double x_vals[] = {1, 2, 3, 4, 5};
  double f_vals[] = {1, 1.9192, 1.7321, 2, 2.2361};

  double x_input;
  cout << "Enter x: ";
  cin >> x_input;

  for (int i = 0; i < 4; i++) {
    if (x_input >= x_vals[i] && x_input <= x_vals[i + 1]) {
      double result = linearInterpolation(x_input, x_vals[i], f_vals[i],
                                          x_vals[i + 1], f_vals[i + 1]);
      cout << "f(" << x_input << ") ≈ " << result << endl;
      return 0;
    }
  }

  cout << "x out of range!" << endl;
  return 0;
}
