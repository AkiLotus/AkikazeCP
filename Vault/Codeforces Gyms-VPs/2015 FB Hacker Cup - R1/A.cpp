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
int primacity[10000007];

// custom typedef here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    for (int i=2; i<10000007; i++) {
        if (!primacity[i]) {
            primacity[i] = 1;
            for (int j=2; j<=10000007/i; j++) {
                primacity[i*j]++;
            }
        }
    }
    int T, cas = 0; cin >> T;
    while (T--) {
        cas++;
        int A, B, K; cin >> A >> B >> K;
        if (K > 8) cout << "Case #" << cas << ": 0\n";
        else {
            cout << "Case #" << cas << ": ";
            int ans = 0;
            for (int i=A; i<=B; i++) {
                if (primacity[i] == K) ans++;
            }
            cout << ans << endl;
        }
    }
	return 0;
}
