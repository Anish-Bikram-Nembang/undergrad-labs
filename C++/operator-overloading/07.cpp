// 7. Overload the * operator to multiply two Complex numbers.
#include <iostream>
class Complex{double r,i;public:Complex(double a,double b):r(a),i(b){}Complex operator*(const Complex&c)const{return{r*c.r-i*c.i,r*c.i+i*c.r};}void display()const{std::cout<<r<<' '<<i<<"i\n";}};
int main(){double r,i,a,b;std::cin>>r>>i>>a>>b;(Complex(r,i)*Complex(a,b)).display();}
