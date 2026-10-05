// 1. Overload the + operator to add two Distance objects (with feet and
// inches).
#include <iostream>
class Distance { int feet, inches; public: Distance(int f=0,int i=0):feet(f+i/12),inches(i%12){} Distance operator+(const Distance&d)const{return{feet+d.feet,inches+d.inches};} void display()const{std::cout<<feet<<" feet "<<inches<<" inches\n";} };
int main(){int f,i,f2,i2;std::cin>>f>>i>>f2>>i2;(Distance(f,i)+Distance(f2,i2)).display();}
