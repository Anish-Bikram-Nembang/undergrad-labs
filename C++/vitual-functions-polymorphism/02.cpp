// 2. Design a class Shape with an overloaded method area() that:
// Calculates area of a circle (given radius)
// Calculates area of a rectangle (given length and breadth)
// Calculates area of a triangle (given base and height)
#include <iostream>
class Shape { public: double area(double radius)const{return 3.141592653589793*radius*radius;} double area(double length,double breadth)const{return length*breadth;} double area(double base,double height,bool)const{return base*height/2;} };
int main(){Shape shape;std::cout<<shape.area(2)<<' '<<shape.area(2,3)<<' '<<shape.area(2,3,true)<<'\n';}
