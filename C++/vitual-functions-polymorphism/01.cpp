// 1. Write a program to create a class Calculator that uses function
// overloading to perform: Addition of two integers Addition of two floats
// Addition of three integers
#include <iostream>
class Calculator { public: int add(int a,int b)const{return a+b;} float add(float a,float b)const{return a+b;} int add(int a,int b,int c)const{return a+b+c;} };
int main(){Calculator c;std::cout<<c.add(2,3)<<' '<<c.add(2.5f,3.5f)<<' '<<c.add(1,2,3)<<'\n';}
