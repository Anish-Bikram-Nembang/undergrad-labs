// 4. Overload the ++ operator (prefix only) for a Counter class that holds an
// integer count.
#include <iostream>
class Counter{int count;public:explicit Counter(int c=0):count(c){}Counter&operator++(){++count;return *this;}void display()const{std::cout<<count<<'\n';}};
int main(){int count;std::cin>>count;Counter counter(count);(++counter).display();}
