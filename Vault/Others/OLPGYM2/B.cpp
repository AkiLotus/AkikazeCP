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
//typedef tuple<i64, i64> tii;
//typedef tuple<i64, i64, i64> tiii;

// global variables here


// custom typedef here
struct tsdd {
	string fi;
	ld x, y;
};

// functions here
bool otherLeg(tsdd a, tsdd b) {
	if (a.y < b.y) return true;
	if (a.y == b.y && a.x > b.x) return true;
	return false;
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int n; cin >> n;
	map<string, bool> M;
	vector<tsdd> A(n);
	ld ans = 999999999.0;
	string first, ath[3];
	for (int i=0; i<n; i++) {
		cin >> A[i].fi >> A[i].x >> A[i].y;
	}
	for (int i=0; i<n; i++) {
		M[A[i].fi] = true;
		ld time = A[i].x;
		vector<tsdd> clone = A; sort(clone.begin(), clone.end(), otherLeg);
		int tmp = 0, q = 0;
		string tmpAth[3];
		while (q < clone.size() && tmp < 3) {
			if (!M[clone[q].fi]) {
				tmpAth[tmp] = clone[q].fi;
				tmp++; time += clone[q].y;
			}
			q++;
		}
		if (time < ans) {
			ans = time; first = A[i].fi;
			for (int j=0; j<3; j++) ath[j] = tmpAth[j];
		}
		M[A[i].fi] = false;
	}
	cout << ans << endl << first;
	for (int i=0; i<3; i++) cout << endl << ath[i];
	return 0;
}
