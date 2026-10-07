#include <iostream>
using namespace std;
class Complex {
private:
  int real;
  int imaginary;

public:
  Complex(int r = 0, int i = 0) {
    real = r;
    imaginary = i;
  }
  Complex operator+(Complex const &c) {
    Complex res;
    res.real = real + c.real;
    res.imaginary = imaginary + c.imaginary;
    return res;
  }
  Complex operator*(Complex const &c) {
    Complex res;
    res.real = real * c.real - imaginary * c.imaginary;
    res.imaginary = real * c.imaginary + imaginary * c.real;
    return res;
  }
  void display() { cout << real << " + " << imaginary << "i"; }
};
int main() {
  Complex a{1, 2}, b{3, 4};
  Complex add = a + b;
  Complex multiply = a * b;

  a.display();
  cout << " + ";
  b.display();
  cout << " = ";
  add.display();
  cout << endl;
  a.display();
  cout << " * ";
  b.display();
  cout << " = ";
  multiply.display();
  cout << endl;

  return 0;
}
