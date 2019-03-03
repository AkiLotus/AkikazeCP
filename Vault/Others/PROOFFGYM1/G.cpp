// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
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
#define tracker1(i) cout << "working at " << i << endl
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// global variables here
i64 lcm_st[2002][2002];

// custom typedef here


// functions here
i64 log2(i64 z) {
    i64 res = 0;
    while (z > 0) {
        z /= 2; res++;
    }
    return res;
}

i64 lcm(i64 a, i64 b) {
    if (a == -1 || b == -1) return -1;
    i64 q = __gcd(a, b);
    a /= q;
    if (log2(a) + log2(b) > 42) return -1;
    return a*b;
}

// File I/O here
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
    //ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    int T; cin >> T;
    while (T--) {
        i64 n; cin >> n;
        i64 ans = 0;
        vector<i64> a(n);
        vector<i64> sum(n, 0);
        for (i64 i=0; i<n; i++) {
            cin >> a[i];
            if (i > 0) sum[i] = sum[i-1] + a[i];
            else sum[i] = a[i];
        }
        for (i64 i=0; i<n; i++) {
            lcm_st[i][i] = a[i];
            for (i64 j=i+1; j<n; j++) {
                lcm_st[i][j] = lcm(lcm_st[i][j-1], a[j]);
            }
        }
        for (i64 i=1; i<=n; i++) {
            for (i64 j=0; j<=n-i; j++) {
                i64 divi = lcm_st[j][i+j-1];
                i64 summate = sum[j+i-1];
                if (j > 0) summate -= sum[j-1];
                if (divi != -1 && summate % divi == 0) ans++;
            }
        }
        cout << ans << endl;
    }
	//fin.close(); fout.close();
	return 0;
}
