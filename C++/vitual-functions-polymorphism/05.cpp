// 5. Create an abstract class Shape with a pure virtual function draw(). Derive
// Circle and Rectangle classes and override draw(). Use base class pointers to
// call the draw() methods.
#include <iostream>
class Shape{public:virtual void draw()const=0;virtual~Shape()=default;};
class Circle:public Shape{public:void draw()const override{std::cout<<"Drawing circle\n";}};
class Rectangle:public Shape{public:void draw()const override{std::cout<<"Drawing rectangle\n";}};
int main(){Circle circle;Rectangle rectangle;Shape*shapes[]={&circle,&rectangle};for(auto shape:shapes)shape->draw();}
