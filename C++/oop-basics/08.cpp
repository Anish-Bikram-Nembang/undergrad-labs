// 8. Create a class Distance with feet and inches. Write a function to add two
// Distance objects and return the result as a new object. Use this function in
// main() to display the total distance.
#include <iostream>
class Distance {
  int feet, inches;
public:
  Distance(int f = 0, int i = 0) : feet(f + i / 12), inches(i % 12) {}
  Distance operator+(const Distance &other) const { return {feet + other.feet, inches + other.inches}; }
  void display() const { std::cout << feet << " feet " << inches << " inches\n"; }
};
int main() { int f, i, f2, i2; std::cin >> f >> i >> f2 >> i2; (Distance(f, i) + Distance(f2, i2)).display(); }
