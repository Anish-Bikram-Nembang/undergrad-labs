#include <iostream>
using namespace std;
class Shape {
public:
  float virtual area() = 0;
};
class Circle : public Shape {
private:
  float radius;

public:
  Circle(float r) : radius{r} {}
  float area() override { return (radius * radius * 22) / 7.0f; }
};
class Rectangle : public Shape {
private:
  float length;
  float breadth;

public:
  Rectangle(float l, float b) : length{l}, breadth{b} {}
  float area() override { return length * breadth; }
};

int main(void) {
  Circle c{4.0f};
  Rectangle r{2.0f, 3.0f};

  Shape *ptr[] = {&c, &r};
  cout << "area of circle: " << ptr[0]->area() << endl;
  cout << "area of rectangle: " << ptr[1]->area() << endl;

  return 0;
}
