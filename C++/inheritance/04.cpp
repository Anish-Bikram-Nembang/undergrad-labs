// 4. Define a base class Shape having data member radius (int). Derive new
// classes called Circle and Sphere from this class. Write methods to compute
// the area of circle and sphere.
#include <iostream>
class Shape { protected: int radius; public: explicit Shape(int r) : radius(r) {} };
class Circle : public Shape { public: using Shape::Shape; double area() const { return 3.141592653589793 * radius * radius; } };
class Sphere : public Shape { public: using Shape::Shape; double area() const { return 4 * 3.141592653589793 * radius * radius; } };
int main() { int radius; std::cin >> radius; std::cout << Circle(radius).area() << ' ' << Sphere(radius).area() << '\n'; }
