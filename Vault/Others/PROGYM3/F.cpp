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
vector<i64> palinCount;
i64 dp[10007][15];

// custom typedef here
typedef pair<string, i64> psi;

// functions here
i64 pow2(i64 z) {
	if (z == 0) return 1;
	return 2*pow2(z-1);
}

i64 ManacherCount(string z) {
    for (i64 i=0; i<=z.size(); i+=2) {
        z.insert(i, 1, '$');
    }
    i64 len = z.size();
    vector<i64> LPS(len, 0);
    i64 center = 0, boundary = 0;
    for (i64 i=1; i<len-1; i++) {
        i64 iMirror = 2 * center - i;
        LPS[i] = (boundary > i) ? min(boundary - i, LPS[iMirror]) : 0;
        while (i-1-LPS[i] >= 0 && i+1+LPS[i] <= len-1 && z[i+1+LPS[i]] == z[i-1-LPS[i]]) LPS[i]++;
    }
    i64 res = 0;
    for (i64 i=0; i<len; i++) {
        LPS[i] = LPS[i] * 2 + 1;
        if (i % 2 == 0) res += LPS[i] / 4;
        else res += (LPS[i] + 1) / 4;
    }
    return res;
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
		for (i64 i=0; i<10007; i++) {
			for (i64 j=0; j<15; j++) dp[i][j] = 0;
		}
        i64 n, q; cin >> n >> q;
        vector<psi> A(n);
        palinCount.resize(n);
        for (i64 i=0; i<n; i++) {
			string z; cin >> z;
			A[i] = mp(z,i);
            palinCount[i] = ManacherCount(z);
        }
        sort(A.begin(), A.end());
        vector<string> B(n);
        for (i64 i=0; i<n; i++) {
			B[i] = A[i].fi;
        }
		for (i64 i=0; i<n; i++) dp[i][0] = i;
		i64 k = (i64)(log(n)/log(2));
		for (i64 j=1; j<=k; j++) {
			for (i64 i=0; i+pow2(j-1)<=n; i++) {
				if (i+pow2(j)-1 >= n) continue;
				if (palinCount[dp[i][j-1]] >= palinCount[dp[i+pow2(j-1)][j-1]]) dp[i][j] = dp[i][j-1];
				else dp[i][j] = dp[i+pow2(j-1)][j-1];
			}
		}
        while (q--) {
            string l, r; cin >> l >> r;
            i64 tl = lower_bound(B.begin(), B.end(), l) - B.begin();
            i64 tr = lower_bound(B.begin(), B.end(), r) - B.begin();
            i64 a = A[tl].se, b = A[tr].se;
            if (a > b) {
                i64 tmp = a; a = b; b = tmp;
            }
            i64 k = (i64)(log(b-a+1)/log(2));
            if (palinCount[dp[a][k]] >= palinCount[dp[b-pow2(k)+1][k]]) cout << dp[a][k]+1 << endl;
            else cout << dp[b-pow2(k)+1][k]+1 << endl;
        }
    }
	//fin.close(); fout.close();
	return 0;
}
