// 9. Overload the != operator to check if two Book objects (title and author)
// are different.
#include <iostream>
#include <string>
class Book{std::string title,author;public:Book(std::string t,std::string a):title(t),author(a){}bool operator!=(const Book&b)const{return title!=b.title||author!=b.author;}};
int main(){std::cout<<(Book("A","X")!=Book("B","Y")?"different\n":"same\n");}
