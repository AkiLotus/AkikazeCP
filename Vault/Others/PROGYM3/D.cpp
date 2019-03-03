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
        i64 n, q; string z; cin >> n >> q >> z;
        vector<vector<i64>> cc;
        for (i64 i=0; i<n; i++) {
            vector<i64> tmp(26, 0);
            cc.pub(tmp);
            cc[i][z[i]-'a']++;
        }
        for (i64 i=1; i<n; i++) {
            for (i64 j=0; j<26; j++) {
                cc[i][j] += cc[i-1][j];
            }
        }
        while (q--) {
            i64 l, r; char c; cin >> l >> r >> c;
            i64 cnum = c - 'a'; l--; r--;
            i64 frontend = l / n, backend = r / n;
            i64 ans = cc[r % n][cnum];
            if (backend > frontend) {
                if (l % n == 0) ans += cc[n-1][cnum] * (backend - frontend);
                else ans += (cc[n-1][cnum] * (backend - frontend) - cc[l % n - 1][cnum]);
            }
            else {
                if (l % n != 0) ans -= cc[l % n - 1][cnum];
            }
            cout << ans << endl;
        }
    }
	//fin.close(); fout.close();
	return 0;
}
