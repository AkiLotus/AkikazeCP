/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
vector<i64> adj[26];
vector<i64> to[26];
vector<bool> visited(26, false);
vector<bool> existed(26, false);
i64 N; vector<string> input;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; input.resize(N);
	for (i64 i=0; i<N; i++) cin >> input[i];
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=0; i<N; i++) {
		if (input[i].size() == 1) {
			existed[input[i][0]-'a'] = true;
			continue;
		}
		for (i64 j=1; j<input[i].size(); j++) {
			i64 p1 = input[i][j-1] - 'a';
			i64 p2 = input[i][j] - 'a';
			if (find(adj[p1].begin(), adj[p1].end(), p2) != adj[p1].end() &&
				find(to[p2].begin(), to[p2].end(), p1) != to[p2].end()) continue;
			if (adj[p1].size() > 0 || to[p2].size() > 0) {
				cout << "NO"; return;
			}
			adj[p1].pub(p2); to[p2].pub(p1);
			existed[p1] = true; existed[p2] = true;
		}
	}
	i64 siz = 0;
	for (i64 i=0; i<26; i++) siz += existed[i];
	string ans = "";
	for (i64 i=0; i<26; i++) {
		if (visited[i] || !existed[i] || to[i].size() == 1) continue;
		queue<i64> Q; Q.push(i); visited[i] = true;
		ans += char(97+i);
		while (!Q.empty()) {
			i64 z = Q.front(); Q.pop();
			if (adj[z].size() == 0) break;
			if (visited[adj[z][0]]) {
				cout << "NO"; return;
			}
			ans += char(97+adj[z][0]);
			visited[adj[z][0]] = true;
			Q.push(adj[z][0]);
		}
	}
	if (ans.size() != siz) cout << "NO";
	else cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
