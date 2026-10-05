// 5. Overload the << operator to print the contents of a Student class (name,
// roll number).
#include <iostream>
#include <string>
class Student{std::string name;int roll;public:Student(std::string n,int r):name(n),roll(r){}friend std::ostream&operator<<(std::ostream&out,const Student&s){return out<<s.name<<' '<<s.roll;}};
int main(){std::cout<<Student("Anish",1)<<'\n';}
