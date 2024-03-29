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


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    int T, cas = 0; cin >> T;
    while (T--) {
        i64 N; cin >> N;
        i64 ans = 0;
        map<string, bool> Map;
        i64 maxlen = 0;
        while (N--) {
            string z; cin >> z;
            bool added = false;
            string tmp = "";
            maxlen = max(maxlen, (i64)z.size());
            for (i64 i=0; i<min((i64)z.size(), maxlen); i++) {
                tmp += z[i];
                if (!added && !Map[tmp]) {
                    //cout << "True there\n";
                    added = true; ans += (i + 1);
                }
                //cout << "tmp = " << tmp << endl;
                Map[tmp] = true;
            }
            if (!added) ans += z.size();
        }
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
	return 0;
}
