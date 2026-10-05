// 10. Overload the += operator to add and assign a Money object (rupees and
// paise).
#include <iostream>
class Money{long long paise;public:Money(long long r=0,long long p=0):paise(r*100+p){}Money&operator+=(const Money&m){paise+=m.paise;return *this;}void display()const{std::cout<<paise/100<<" rupees "<<paise%100<<" paise\n";}};
int main(){Money money(10,50);money+=Money(5,75);money.display();}
