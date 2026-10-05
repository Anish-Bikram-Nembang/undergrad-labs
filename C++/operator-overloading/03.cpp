// 3. Overload the == operator to compare two Point objects (with x and y
// coordinates).
#include <iostream>
class Point{int x,y;public:Point(int a,int b):x(a),y(b){}bool operator==(const Point&p)const{return x==p.x&&y==p.y;}};
int main(){int x,y,a,b;std::cin>>x>>y>>a>>b;std::cout<<(Point(x,y)==Point(a,b)?"equal\n":"different\n");}
