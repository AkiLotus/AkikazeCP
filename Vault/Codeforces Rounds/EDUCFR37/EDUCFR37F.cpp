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


/** -----GLOBAL VARIABLES----- **/
i64 N, M; vi D(1000001, 1);
vi a, leafPos;
vi treeD(3000000, 0);
vi treeZ_stop(3000000, 0);

/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild(i64 n, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		leafPos[st] = n;
		treeD[n] = a[st]; return;
	}
	ITBuild(n*2, st, (st+en)/2);
	ITBuild(n*2+1, (st+en)/2+1, en);
	treeD[n] = treeD[n*2] + treeD[n*2+1];
}

i64 ReturnSum(i64 n, i64 st, i64 en, i64 L, i64 R) {
    //cout << "working at node " << n << ": " << st << "->" << en << endl;
	if (L > en || R < st || st > en) return 0;
	if (st >= L && en <= R) return treeD[n];
	i64 p1 = ReturnSum(n*2, st, (st+en)/2, L, R);
	i64 p2 = ReturnSum(n*2+1, (st+en)/2+1, en, L, R);
	return p1 + p2;
}

void IncUpdate(i64 n, i64 st, i64 en, i64 L, i64 R, i64 x) {
    //cout << "working at node " << n << ": " << st << "->" << en << endl;
    if (treeZ_stop[n] == en-st+1) return;
	if (L > en || R < st || st > en) return;
	if (st == en) {
		treeD[n] = D[treeD[n]];
		if (D[treeD[n]] == treeD[n]) treeZ_stop[n] = 1;
		return;
	}
	IncUpdate(n*2, st, (st+en)/2, L, R, x);
	IncUpdate(n*2+1, (st+en)/2+1, en, L, R, x);
	treeD[n] = treeD[n*2] + treeD[n*2+1];
	treeZ_stop[n] = treeZ_stop[n*2] + treeZ_stop[n*2+1];
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	D[1] = 1;
	for (i64 i=2; i<1000001; i++) {
		if (D[i] == 1) {
			i64 tmp = i, cnt = 2;
			while (tmp < 1000001) {
				D[tmp] = cnt;
				for (i64 j=2; j<=1000000/tmp; j++) {
					if (j % i == 0) continue;
					D[tmp*j] *= cnt;
				}
				cnt++; tmp *= i;
			}
		}
	}
	cin >> N >> M; a.resize(N); leafPos.resize(N);
	for (i64 i=0; i<N; i++) cin >> a[i];
	ITBuild(1, 0, N-1);
	//for (i64 i=1; i<=10; i++) {
	//	for (i64 j=0; j<DQ[i].size(); j++) cout << DQ[i][j] << " ";
	//	cout << endl;
	//}
}

void ProSolve() {
	while (M--) {
	    //cout << "RE here?\n";
		i64 cmd, l, r; cin >> cmd >> l >> r;
		if (cmd == 1) { // REPLACE
			IncUpdate(1, 0, N-1, l-1, r-1, 1);
		}
		else if (cmd == 2) { // SUM
			cout << ReturnSum(1, 0, N-1, l-1, r-1) << endl;
		}
		//for (i64 i=0; i<N; i++) cout << a[i] << " "; cout << endl;
	    //cout << "RE here?\n";
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}