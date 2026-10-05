// 8. Overload the / operator to divide two Fraction objects (numerator and
// denominator).
#include <iostream>
class Fraction{long long n,d;public:Fraction(long long a,long long b):n(a),d(b){}Fraction operator/(const Fraction&f)const{return{n*f.d,d*f.n};}void display()const{std::cout<<n<<'/'<<d<<'\n';}};
int main(){long long n,d,a,b;std::cin>>n>>d>>a>>b;if(!d||!a||!b)return 1;(Fraction(n,d)/Fraction(a,b)).display();}
