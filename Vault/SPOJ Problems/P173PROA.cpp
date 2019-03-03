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

// custom typedef here


// global variables here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	// code here
	map<i64, i64> M;
	map<i64, i64> prev;
	map<pii, bool> check;
	i64 n, ans = 0; cin >> n;
	vector<i64> a(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; M[a[i]]++;
	}
	sort(a.begin(), a.end());
	for (i64 i=0; i<n-1; i++) {
		for (i64 j=i+1; j<n; j++) {
			if (check[mp(a[i], a[j])]) continue;
			check[mp(a[i], a[j])] = true;
			i64 tmpSum = 2;
			M[a[i]]--; M[a[j]]--;
			i64 last1 = a[i], last2 = a[j];
			while (M[last1 + last2] != 0) {
				M[last1 + last2]--;
				prev[last1+last2] = last2;
				i64 tmp = last1 + last2;
				last1 = last2; last2 = tmp;
				tmpSum++;
			}
			i64 z = last2; M[z]++;
			while (z != a[j] && prev[z] != a[j]) {
				z = prev[z]; M[z]++;
			}
			M[a[i]]++; M[a[j]]++;
			ans = max(ans, tmpSum);
		}
	}
	cout << ans;
	return 0;
}
