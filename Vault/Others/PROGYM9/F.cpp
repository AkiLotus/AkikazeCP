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
typedef pair<int, string> pis;

// global variables here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int T; cin >> T;
	while (T--) {
		map<string, vector<string>> Map;
		map<string, int> Ranking;
		int N; cin >> N;
		vector<string> C;
		vector<pis> A;
		for (int i=0; i<N; i++) {
			string z1, z2, z3; cin >> z1 >> z2 >> z3;
			if (find(C.begin(), C.end(), z1) == C.end()) C.pub(z1);
			if (find(C.begin(), C.end(), z2) == C.end()) C.pub(z2);
			if (find(C.begin(), C.end(), z3) == C.end()) C.pub(z3);
			Map[z1].pub(z2); Map[z1].pub(z3);
			Map[z2].pub(z1); Map[z2].pub(z3);
			Map[z3].pub(z2); Map[z3].pub(z1);
		}
		queue<string> Q; Q.push("Ahmad");
		while (!Q.empty()) {
			string tmp = Q.front(); Q.pop();
			for (int i=0; i<Map[tmp].size(); i++) {
				if (Ranking[Map[tmp][i]] == 0 && Map[tmp][i] != "Ahmad") {
					Ranking[Map[tmp][i]] = Ranking[tmp] + 1;
					Q.push(Map[tmp][i]);
				}
			}
		}
		for (int i=0; i<C.size(); i++) {
			if (Ranking[C[i]] == 0 && C[i] != "Ahmad")  A.pub(mp(999999999, C[i]));
			else A.pub(mp(Ranking[C[i]], C[i]));
		}
		sort(A.begin(), A.end());
		cout << A.size() << endl;
		for (int i=0; i<A.size(); i++) {
			cout << A[i].se << " ";
			if (A[i].fi == 999999999) cout << "undefined\n";
			else cout << A[i].fi << endl;
		}
	}
	return 0;
}
