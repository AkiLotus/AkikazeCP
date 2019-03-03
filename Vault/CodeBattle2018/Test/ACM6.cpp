/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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


/** -----GLOBAL VARIABLES----- **/
i64 n, x, y, ans = 0, siz; vi affected, a;
map<i64, i64> Map;
map<i64, i64> M;
vector<i64> distinctValue;
vector<i64> leafPos;
i64 sumTree[666666];

/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		leafPos[st] = node;
		return;
	}
	ITBuild(node*2, st, (st+en)/2);
	ITBuild(node*2+1, (st+en)/2+1, en);
}
 
void ITUpdate(i64 z) {
	i64 node = leafPos[z];
	while (node > 0) {
		sumTree[node]++; node /= 2;
	}
}
 
i64 ITGet(i64 node, i64 left, i64 right, i64 st, i64 en) {
	if (left > right) return 0;
	if (right < st || en < left) return 0;
	if (st <= left && right <= en) return sumTree[node];
	i64 p1 = ITGet(node*2, left, (left+right)/2, st, en);
	i64 p2 = ITGet(node*2+1, (left+right)/2+1, right, st, en);
	return (p1 + p2);
}

void solveAffectedVal() {
	i64 N = a.size();
	for (i64 i=0; i<N; i++) {
		M[a[i]]++;
		if (M[a[i]] == 1) {
			distinctValue.pub(a[i]);
		}
	}
	siz = distinctValue.size();
	sort(distinctValue.begin(), distinctValue.end());
	leafPos.resize(siz, 0);
	ITBuild(1, 0, siz-1);
	for (i64 i=N-1; i>=0; i--) {
		i64 position = lower_bound(distinctValue.begin(), distinctValue.end(), a[i]) - distinctValue.begin();
		ITUpdate(position);
		ans += ITGet(1, 0, siz-1, 0, position-1);
	}
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
}

void ProSolve() {
	while (n--) {
		i64 x, y; cin >> x >> y;
		if (Map.find(x) == Map.end()) {
			Map[x] = x; affected.pub(x);
		}
		if (Map.find(y) == Map.end()) {
			Map[y] = y; affected.pub(y);
		}
		i64 tmp = Map[x]; Map[x] = Map[y]; Map[y] = tmp;
	}
	sort(affected.begin(), affected.end()); //cout << affected << endl;
	for (map<i64, i64>::iterator it=Map.begin(); it!=Map.end(); it++) a.pub(it->second);
	for (map<i64, i64>::iterator it=Map.begin(); it!=Map.end(); it++) {
		i64 val = it->second, index = it->first;
		if (val > index) continue;
		i64 pos1 = lower_bound(affected.begin(), affected.end(), val+1) - affected.begin();
		i64 pos2 = lower_bound(affected.begin(), affected.end(), index) - affected.begin();
		//cout << pos1 << " " << pos2 << endl;
		ans += (index - val - 1 - (pos2 - pos1)); //cout << "ans = " << ans << endl;
	}
	for (map<i64, i64>::iterator it=Map.begin(); it!=Map.end(); it++) {
		i64 val = it->second, index = it->first;
		if (val < index) continue;
		i64 pos1 = lower_bound(affected.begin(), affected.end(), val) - affected.begin();
		i64 pos2 = lower_bound(affected.begin(), affected.end(), index+1) - affected.begin();
		//cout << pos1 << " " << pos2 << endl;
		ans += (val - index - 1 - (pos1 - pos2)); //cout << "ans = " << ans << endl;
	}
	solveAffectedVal();
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}