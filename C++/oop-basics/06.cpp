// 6. Create a class Box with data members length, breadth, and height. Overload
// constructors to: 	Accept no arguments (set default size), 	One
// argument (cube), 	Three arguments (cuboid). 	Add a function to calculate the
// volume.
#include <iostream>
class Box {
  double length, breadth, height;
public:
  Box() : length(1), breadth(1), height(1) {}
  explicit Box(double side) : length(side), breadth(side), height(side) {}
  Box(double l, double b, double h) : length(l), breadth(b), height(h) {}
  double volume() const { return length * breadth * height; }
};
int main() { double a, b, c; std::cin >> a >> b >> c; std::cout << Box(a, b, c).volume() << '\n'; }
