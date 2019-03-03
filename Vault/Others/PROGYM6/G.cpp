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
vector<int> a(11, 0);
vector<bool> visited(11, false);
int ans = -1;
int N, S;

// custom typedef here


// functions here
void Try_(int lim, int cc, int start, int sum, int last) {
	if (ans != -1) return;
	if (last + (lim - cc) >= N) return;
	if (cc == lim) {
		if (sum < S) return;
		if (sum - a[start] < S) {
			ans = lim;
		}
		return;
	}
	for (int i=last+1; i<N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			Try_(lim, cc+1, start, sum+a[i], i);
			visited[i] = false;
		}
	}
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
	int t; cin >> t;
	while (t--) {
		ans = -1;
		cin >> N >> S;
		for (int i=0; i<N; i++) cin >> a[i];
		sort(a.begin(), a.begin()+N);
		for (int i=N; i>=1; i--) {
			if (ans != -1) break;
			for (int j=0; j<11; j++) visited[j] = false;
			for (int j=0; j<=N-i; j++) Try_(i, 1, j, a[j], j);
		}
		cout << ans << endl;
	}
	//fin.close(); fout.close();
	return 0;
}
