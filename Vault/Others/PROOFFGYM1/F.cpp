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

int main()
{
    //ifstream fin; ofstream fout;
    //fin.open(problemName+in); fout.open(problemName+out);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // code here
    int T; cin >> T;
    while (T--) {
        i64 n, k; cin >> n >> k;
        vector<i64> a(n);
        vector<i64> s(n);
        vector<i64> next_(n);
        vector<i64> near_(n);
        for (i64 i=0; i<n; i++) {
            cin >> a[i];
            s[i] = a[i];
        }
        sort(s.begin(), s.end());
        for (i64 i=0; i<n; i++) {
            a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
            near_[i] = n+1;
        }
        for (i64 i=n-1; i>=0; i--) {
            next_[i] = near_[a[i]];
            near_[a[i]] = i;
        }
        set<pii> store;
        i64 ans = n;
        for (i64 i=0; i<n; i++) {
            auto it = store.find(mp(i, a[i]));
            if (it != store.end()) {
                ans--; store.erase(it);
                near_[a[i]] = next_[i];
            }
            else if (store.size() >= k) {
                auto tmp = --store.end();
                store.erase(tmp);
            }
            store.insert(mp(next_[i], a[i]));
            near_[a[i]] = next_[i];
        }
        cout << ans << endl;
    }
    //fin.close(); fout.close();
    return 0;
}
