#include <bits/stdc++.h>

using namespace std;

double X, Y ;

double area(double h){
    return (X - 2*h)*(Y-2*h)*h ;
}

void ptb2(double a, double b, double c){
	double d=b*b-4*a*c;
	double x1=(-b+sqrt(d))/(2*a);
	double x2=(-b-sqrt(d))/(2*a);
    double ans = max(area(x1) , area(x2));
    cout << fixed << setprecision(6) << ans <<endl;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
    int T;
    cin >> T ;
    while (T--){
		cin >> X >> Y ;
        double a = X + Y ;
        double b = X * Y ;
        ptb2((double)12 , -(double)4*a , b) ;
    }
}
