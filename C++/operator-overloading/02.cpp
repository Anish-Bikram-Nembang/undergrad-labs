// 2. Overload the - operator to subtract two Time objects (with hours and
// minutes).
#include <iostream>
class Time { int h,m; public: Time(int a=0,int b=0):h(a+b/60),m(b%60){} Time operator-(const Time&t)const{int total=h*60+m-t.h*60-t.m;return{total/60,total%60};} void display()const{std::cout<<h<<" hours "<<m<<" minutes\n";} };
int main(){int h,m,h2,m2;std::cin>>h>>m>>h2>>m2;(Time(h,m)-Time(h2,m2)).display();}
