/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
struct pii_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return (h1 * 1000000000LL + h2);  
	}
};


/** -----GLOBAL VARIABLES----- **/
i64 n, m; set<pii> S;
vi degree;
unordered_map<pii, i64, pii_hash> Map;
vi dp, ans; queue<i64> Q;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> m; dp.resize(n, -1);
	degree.resize(n, n-1);
	while (m--) {
		i64 x, y; cin >> x >> y; x--; y--;
		Map[mp(x,y)]++; Map[mp(y,x)]++;
		degree[x]--; degree[y]--;
	}
	for (i64 i=0; i<n; i++) S.insert(mp(-degree[i], i));
	i64 first = (*S.begin()).se; S.erase(S.begin());
	Q.push(first); dp[first] = 0;
}

void ProSolve() {
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop();
		//tracker1(z);
		vi toErase;
		for (auto it=S.begin(); it!=S.end(); it++) {
			i64 w = (*it).se;
			if (!Map[mp(z,w)]) {
				dp[w] = dp[z];
				toErase.pub(w); Q.push(w);
			}
		}
		for (i64 i=0; i<toErase.size(); i++) S.erase(S.find(mp(-degree[toErase[i]], toErase[i])));
		if (Q.empty() && !S.empty()) {
			i64 w = (*S.begin()).se; dp[w] = dp[z] + 1;
			Q.push(w); S.erase(S.begin());
		}
		//cout << "RE here?\n";
	}
	ans.resize(*max_element(dp.begin(), dp.end()) + 1, 0);
	for (i64 i=0; i<n; i++) ans[dp[i]]++;
	sort(ans.begin(), ans.end()); cout << ans.size() << endl;
	for (i64 i=0; i<ans.size(); i++) cout << ans[i] << " ";
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}