// 2. Create an Employee class containing employeeId, name, basicSalary, and
// allowance. Write a program that: Accepts details of multiple employees.
// Calculates the gross salary.
// Stores the employee records in a file.
// Reads the records from the file and displays them.
// Exception requirement: Throw an exception if the basic salary or allowance is
// negative.
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
struct Employee{int id;std::string name;double basic,allowance;};
int main(){int count;std::cin>>count;if(count<0)return 1;std::ofstream out("employees.txt");if(!out)return 1;for(int i=0;i<count;++i){Employee e;std::cin>>e.id>>e.name>>e.basic>>e.allowance;if(e.basic<0||e.allowance<0)throw std::invalid_argument("negative salary");out<<e.id<<' '<<e.name<<' '<<e.basic<<' '<<e.allowance<<'\n';}out.close();std::ifstream in("employees.txt");Employee e;while(in>>e.id>>e.name>>e.basic>>e.allowance)std::cout<<e.id<<' '<<e.name<<' '<<e.basic+e.allowance<<'\n';}
