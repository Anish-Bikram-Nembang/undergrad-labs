// 6. Overload the >> operator to input data into a Rectangle class (length and
// breadth).
#include <iostream>
class Rectangle{int length=0,breadth=0;friend std::istream&operator>>(std::istream&,Rectangle&);public:void display()const{std::cout<<length*breadth<<'\n';}};
std::istream&operator>>(std::istream&in,Rectangle&r){return in>>r.length>>r.breadth;}
int main(){Rectangle rectangle;std::cin>>rectangle;rectangle.display();}
