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
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	string z; cin >> z;
	if (z.size() < 6) {
		cout << "0"; return 0;
	}
	i64 lastUp = -1, lastLow = -1, lastNum = -1, ans = 0;
	for (i64 i=0; i<6; i++) {
		if (z[i] >= 'A' && z[i] <= 'Z') lastUp = i;
		else if (z[i] >= 'a' && z[i] <= 'z') lastLow = i;
		else if (z[i] >= '0' && z[i] <= '9') lastNum = i;
	}
	if (lastUp != -1 && lastLow != -1 && lastNum != -1) {
		cout << "Initial 6 is a valid string\n";
		ans++;
	}
	for (i64 i=6; i<z.size(); i++) {
		if (z[i] >= 'A' && z[i] <= 'Z') lastUp = i;
		else if (z[i] >= 'a' && z[i] <= 'z') lastLow = i;
		else if (z[i] >= '0' && z[i] <= '9') lastNum = i;
		if (lastUp != -1 && lastLow != -1 && lastNum != -1) {
			cout << "Additional " << min(min(lastUp, min(lastLow, lastNum))+1, i-5) << " string ended at index " << i << endl;
			ans += min(min(lastUp, min(lastLow, lastNum))+1, i-5);
		}
	}
	cout << ans;
	return 0;
}
