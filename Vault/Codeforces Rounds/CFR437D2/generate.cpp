// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define MOD 1000000007LL
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here

// functions here

char* problemName = "CFR437D2C";
char* in = ".INP";
char* out = ".OUT";

int main() {
	//freopen(strcat(problemName,in), "r", stdin);
	freopen("CFR437D2C.OUT", "w", stdout);
    cout << "100000 100000\n";
    for (int i=0; i<100000; i++) {
        if (i % 2 == 0) cout << i+4 << " 1 100000\n";
        else cout << i+3 << " 100000 1\n";
    }
	return 0;
}
