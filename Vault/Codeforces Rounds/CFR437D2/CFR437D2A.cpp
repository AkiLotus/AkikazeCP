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

string problemName = "";
char* in = ".INP";
char* out = ".OUT";

int main() {
	//freopen(strcat(problemName,in), "r", stdin);
	//freopen(strcat(problemName,out), "w", stdout);
	ios_base::sync_with_stdio(0);
	int n; string z; cin >> n >> z;
	int sf = 0, fs = 0;
	for (int i=0; i<n-1; i++) {
        if (z[i] == 'S' && z[i+1] == 'F') sf++;
        else if (z[i] == 'F' && z[i+1] == 'S') fs++;
	}
	if (sf > fs) cout << "YES";
	else cout << "NO";
	return 0;
}
