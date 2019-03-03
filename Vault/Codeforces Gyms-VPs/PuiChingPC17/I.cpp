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
	i64 N, ans = 0; cin >> N;
	vector<i64> H(N), diff(N, 0);
	for (i64 i=0; i<N; i++) {
		cin >> H[i];
		if (i == 0) continue;
		ans += abs(H[i] - H[i-1]);
		diff[i-1] = (abs(H[i] - H[i-1])-abs(H[i]+H[i-1]));
		//cout << diff[i-1] << " ";
	}
	if (N == 1) cout << 0;
	else if (N == 2) {
		cout << min(abs(H[0] - H[1]), abs(H[0] + H[1]));
	}
	else {
		//cout << diff[N-1] << endl << ans << endl;
		sort(diff.begin(), diff.end());
		if (diff[N-1] + diff[N-2] > 0) ans -= (diff[N-1] + diff[N-2]);
		cout << ans;
	}
	//fin.close(); fout.close();
	return 0;
}
