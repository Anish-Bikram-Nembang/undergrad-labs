// 7. Create a base class Employee with a virtual function calculateSalary().
// Derive FullTimeEmployee and PartTimeEmployee with different implementations
// of calculateSalary(). Show how polymorphism helps manage different employee
// types.
#include <iostream>
class Employee{public:virtual double calculateSalary()const=0;virtual~Employee()=default;};
class FullTimeEmployee:public Employee{double salary;public:explicit FullTimeEmployee(double s):salary(s){}double calculateSalary()const override{return salary;}};
class PartTimeEmployee:public Employee{double rate,hours;public:PartTimeEmployee(double r,double h):rate(r),hours(h){}double calculateSalary()const override{return rate*hours;}};
int main(){FullTimeEmployee full(50000);PartTimeEmployee part(20,80);Employee*employees[]={&full,&part};for(auto employee:employees)std::cout<<employee->calculateSalary()<<'\n';}
