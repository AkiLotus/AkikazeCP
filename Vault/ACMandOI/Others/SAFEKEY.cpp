// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// global variables here


// custom typedef here


// functions here
i64 f(string z, bool left) {
    i64 hez = 10 * (z[0] - '0') + (z[1] - '0');
    i64 res = 90*(z.size()-2) + hez;
    string stz = "";
    i64 diff = (z[1] - z[0] < 0) ? (z[1] - z[0]) + 10 : (z[1] - z[0]);
    for (i64 i=0; i<z.size(); i++) {
        if (i < 2) stz += z[i];
        else {
            stz += ".";
            stz[i] = '0' + (((stz[i-1] - '0') + diff) % 10);
        }
    }
    if ((left && stz < z) || (!left && stz <= z)) res++;
    return res;
}


int main() {
	freopen("SAFEKEY.INP", "r", stdin);
	freopen("SAFEKEY.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    string nl, nr; cin >> nl >> nr;
    i64 fl = f(nl, 1), fr = f(nr, 0);
    i64 ans = fr - fl;
    cout << ans;
	return 0;
}
