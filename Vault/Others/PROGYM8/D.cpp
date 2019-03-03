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
int M, N;
vector<int> a, b;
bool Mutable = false;
map<vector<int>, bool> Map;

// custom typedef here


// functions here
bool vEqual(vector<int> a, vector<int> b) {
	if (a.size() != b.size()) return false;
	for (int i=0; i<a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void Try_(vector<int> x) {
	//cout << "working at vector x:"; for (int i=0; i<x.size(); i++) cout << " " << x[i]; cout << endl;
	vector<int> rx = x; reverse(rx.begin(), rx.end());
	if (Mutable) return;
	if (vEqual(x,b) || vEqual(rx,b)) {
		Mutable = true; return;
	}
	if (x.size() <= N) return;
	if (Map[x]) return;
	Map[x] = true;
	int qq = x.size();
	for (int i=1; i<=qq/2; i++) {
		vector<int> x1 = x, x2 = x;
		for (int j=0; j<i; j++) {
			x1[2*i-1-j] += x1[j];
			x2[qq-2*i+j] += x2[qq-1-j];
		}
		for (int j=0; j<i; j++) {
			x1.erase(x1.begin()); x2.erase(x2.end()-1);
		}
		vector<int> y1 = x1, y2 = x2;
		reverse(y1.begin(), y1.end()); reverse(y2.begin(), y2.end());
		Try_(x1);
		if (Mutable) return;
		Try_(x2);
		if (Mutable) return;
		Try_(y1);
		if (Mutable) return;
		Try_(y2);
	}
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	cin >> M; a.resize(M);
	for (int i=0; i<M; i++) cin >> a[i];
	cin >> N; b.resize(N);
	for (int i=0; i<N; i++) cin >> b[i];
	Try_(a);
	if (Mutable) cout << "S"; else cout << "N";
	return 0;
}
